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
