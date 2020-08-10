#include <vector>
#include <map>
#include <tuple>
#include <deque>
#include <array>
#include <bitset>
template<class T>
class graph{
public:
  virtual void add_vertex(std::size_t ,std::size_t ,T )=0;
  virtual void del_vertex(std::size_t ,std::size_t)=0;
  virtual std::tuple<bool,T> get_cost(std::size_t ,std::size_t )=0;
  virtual std::vector<std::tuple<T,std::size_t> > get_next(std::size_t)=0;
  virtual std::size_t size()=0;
};
template<class T> 
class matrix_graph :graph<T>{
  std::vector<std::vector<T> > _matrix;
  std::vector<bool> _is_connected;
  std::size_t N;
public:
  matrix_graph(std::size_t n) {
    N=n;
    _is_connected.resize(n*n);
    _matrix.resize(n);
    for (std::size_t i = 0; i < n; i++) {
      _matrix[i].resize(n);
    }
  }
  void add_vertex(std::size_t from, std::size_t to, T cost) {
    _matrix[from][to]=cost;
    _is_connected[from*N+to]=true;
  }
  void del_vertex(std::size_t from, std::size_t to) {
    _is_connected[from*N+to]=false;
  }
  std::tuple<bool, T> get_cost(std::size_t from, std::size_t to) {
    if (_is_connected[from*N+to])return { _matrix[from][to], true };
    else return { false, _matrix[from][to] };
  }
  std::vector<std::tuple<T, std::size_t> > get_next(std::size_t from) {
    std::vector<std::tuple<T, std::size_t> > ret;
    for (std::size_t i = 0; i < N; i++) {
      if (_is_connected[from*N+i])ret.push_back({ _matrix[from][i], i });
    }
    return ret;
  }
  std::size_t size() {
    return N;
  }
};

template<class T>
class ref_graph: graph<T> {
  std::vector<std::map<std::size_t,T>> _nodes;
public:
  ref_graph(std::size_t n):{
    _nodes.resize(n);
  }
  ref_graph(std::vector<std::map<std::size_t,T>> n):_nodes(n){
    
  }
  void add_vertex(std::size_t from,std::size_t to,T cost){
    _nodes[from][to]=cost;
  }
  void del_vertex(std::size_t from,std::size_t to){
    _nodes[from].erase(to);
  }
  std::tuple<bool,T> get_cost(std::size_t from,std::size_t to){
    try {
      return {true,_nodes[from][to]};
    } catch (std::out_of_range&) {
      return {false,T()};
    }
  }
  std::vector<std::tuple<T,std::size_t> > get_next(std::size_t from){
    std::vector<std::tuple<T,std::size_t> > ret;
    for(auto i=_nodes[from].begin();i!=_nodes[from].end();++i){
      ret.push_back({i->second,i->first});
    }
    return ret;
  }
  std::size_t size(){return _nodes.size();}
};
