#include <vector>
#include <map>
#include <tuple>
#include <deque>
#include <array>
#include <bitset>
template<typename T> 
struct matrix_node{
  T cost;
  bool isConnected;
};
template<class T>
class graph{
public:
  virtual void add_vector(std::size_t ,std::size_t ,T )=0;
  virtual void del_vector(std::size_t ,std::size_t ,T )=0;
  virtual matrix_node<T> get_cost(std::size_t ,std::size_t )=0;
};
template<class T> 
class matrix_graph :graph<T>{
  std::vector<std::vector<T> > _matrix;
  std::vector<bool> _is_connected;
  std::size_t N;
public:
    matrix_graph(std::size_t n){
      N=n;
      _is_connected.resize(n*n);
      _matrix.resize(n);
      for (std::size_t i = 0; i < n; i++) {
        _matrix[i].resize(n);
      }
    }
    void add_vector(std::size_t from,std::size_t to,T cost){
      _matrix[from][to]=cost;
      _is_connected[from*N+to]=true;
    }
    void del_vector(std::size_t from,std::size_t to){
      _is_connected[from*N+to]=false;
    }
    struct matrix_node<T> get_cost(std::size_t from,std::size_t to){
      if(_is_connected[from*N+to])return {_matrix[from][to],true};
      else return {_matrix[from][to],false};
    }
};

template<class T> 
class ref_graph: graph<T> {
  std::vector<std::map<std::size_t,T>> _nodes;
  bool _is_sorted;
  void _sort(){if(_is_sorted==false){sort(_nodes.begin(),_nodes.end());_is_sorted=true;}}
  public:
    ref_graph(std::size_t n):_is_sorted(false){
      _nodes.resize(n);
    }
    void add_vector(std::size_t from,std::size_t to,T cost){
      _nodes[from][to]=cost;
    }
    void del_vector(std::size_t from,std::size_t to){
      _nodes[from].erase(to);
    }
    struct matrix_node<T> get_cost(std::size_t from,std::size_t to){
      try {
        return {_nodes[from][to],true};
      } catch (std::out_of_range&) {
        return {T(),false};
      }
    }
};
