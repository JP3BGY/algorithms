---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Depends on

* :warning: <a href="../datastructure/graph.cpp.html">datastructure/graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <queue>
#include "../datastructure/graph.cpp"
template<class T>
std::vector<T,std::size_t> dijkstra_vec(graph<T> g,std::size_t from){
  std::vector<T,std::size_t> res(g.size());
  std::priority_queue<std::tuple<T,std::size_t,std::size_t> > q;
  q.push({0,from,from});
  while(q.empty()==false){
    auto v=q.top();q.pop();
    res[std::get<1>(v)]={std::get<0>(v),std::get<2>(v)};
    auto vec=g.get_next(std::get<1>(v));
    for(auto i:vec){
      q.push({std::get<0>(v)+std::get<0>(i),std::get<1>(i),std::get<1>(v)});
    }
  }
  return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.cpp"
#include <queue>
#line 1 "graph/../datastructure/graph.cpp"
#include <vector>
#include <map>
#include <tuple>
#include <deque>
#include <array>
#include <bitset>
template<class T>
class graph{
public:
  virtual void add_vector(std::size_t ,std::size_t ,T )=0;
  virtual void del_vector(std::size_t ,std::size_t ,T )=0;
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
    std::tuple<bool,T> get_cost(std::size_t from,std::size_t to){
      if(_is_connected[from*N+to])return {_matrix[from][to],true};
      else return {false,_matrix[from][to]};
    }
    std::vector<std::tuple<T,std::size_t> > get_next(std::size_t from){
      std::vector<std::tuple<T,std::size_t> > ret;
      for (std::size_t i = 0; i < N; i++) {
        if(_is_connected[from*N+i])ret.push_back({_matrix[from][i],i});
      }
      return ret;
    }
    std::size_t size(){return N;}
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
    void add_vector(std::size_t from,std::size_t to,T cost){
      _nodes[from][to]=cost;
    }
    void del_vector(std::size_t from,std::size_t to){
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
#line 3 "graph/dijkstra.cpp"
template<class T>
std::vector<T,std::size_t> dijkstra_vec(graph<T> g,std::size_t from){
  std::vector<T,std::size_t> res(g.size());
  std::priority_queue<std::tuple<T,std::size_t,std::size_t> > q;
  q.push({0,from,from});
  while(q.empty()==false){
    auto v=q.top();q.pop();
    res[std::get<1>(v)]={std::get<0>(v),std::get<2>(v)};
    auto vec=g.get_next(std::get<1>(v));
    for(auto i:vec){
      q.push({std::get<0>(v)+std::get<0>(i),std::get<1>(i),std::get<1>(v)});
    }
  }
  return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

