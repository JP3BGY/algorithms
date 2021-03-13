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
template<class T>
bool chmin(T& a,const T& b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
auto dijkstra = [&](long s,std::vector<std::vector<long>> &graph){
  using namespace std;
  typedef std::pair<long,long> pll;
  priority_queue<pll,vector<pll>,greater<pll>> q;
  vector<long> dist(graph.size(),(1LL<<60));
  q.push(pll(0,s));
  dist[s]=0;
  while(!q.empty()){
    auto [d,p]=q.top();q.pop();
    if(d>dist[p])continue;
    for (auto &&next : graph[p])
    {
      if(chmin(dist[next],d+1)){
        q.push(pll(d+1,next));
      }
    }
  }
  return dist;
};
auto dijkstra_with_weight = [&](long long s,std::vector<std::vector<std::pair<long long,long long>>> &graph){
  using namespace std;
  typedef long long ll;
  typedef std::pair<ll,ll> pll;
  priority_queue<pll,vector<pll>,greater<pll>> q;
  vector<ll> dist(graph.size(),(1LL<<60));
  q.push(pll(0,s));
  dist[s]=0;
  while(!q.empty()){
    auto [d,p]=q.top();q.pop();
    if(d>dist[p])continue;
    chmin(dist[p],d);
    for (auto &&[next,weight] : graph[p])
    {
      if(chmin(dist[next],d+weight)){
        q.push(pll(d+weight,next));
      }
    }
  }
  return dist;
};