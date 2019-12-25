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


# :warning: graph/stronglyconnected.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/stronglyconnected.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<iostream>
#include<set>
#include<utility>
#include<assert.h>
#ifdef ENABLE_DEBUG
#define dump(a) std::cerr<<#a<<"="<<a<<std::endl
#define dumparr(a,n) std::cerr<<#a<<"["<<n<<"]="<<a[n]<<std::endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
std::vector<std::vector<int>> graph;
std::vector<bool> used;
std::vector<int> order;
std::vector<int> group;
std::vector<std::vector<int>> t;
std::vector<std::vector<int>> rev_graph(graph.size());
void dfs(int i){
    if(used[i]==true){
        return;
    }
    used[i]=true;
    for (auto &&to : graph[i])
    {
        dfs(to);
    }
    order.push_back(i);
}
void rdfs(int idx,int g){
    if(group[idx]!=-1)return;
    group[idx]=g;
    for (auto &&to : rev_graph[idx])
    {
        rdfs(to,g);
    }
    
}
std::vector<std::vector<int>> strongly_connected(){
    used.resize(graph.size());
    fill(used.begin(),used.end(),false);
    group.resize(graph.size());
    rev_graph.resize(graph.size());
    for(int i=0;i<graph.size();i++){
        if(used[i]==false){
            dfs(i);
        }
    }
    for (int i=0;i<graph.size();i++)
    {
        for (auto &&j : graph[i])
        {
            rev_graph[j].push_back(i);
        }
    }
    std::fill(group.begin(),group.end(),-1);
    int g=0;
    reverse(order.begin(),order.end());
    for (auto &&i : order)
    {
        if(group[i]!=-1)continue;
        rdfs(i,g++);
    }
    t.resize(g);
    for(long long i = 0; i < group.size(); i++){
        t[group[i]].push_back(i);        
    }
    return t;
}
int V,E;
//ソートしたときに変数とその否定が連続するように2倍して偶奇で否定がついているかどうかを見分ける形にする
inline int VAR(int x){
    if(x<0){
        x=-x;
        x-=1;
        x<<=1;
        x+=1;
    }else{
        x-=1;
        x<<=1;
    }
    return x;
}
//VARの逆関数、出力用
inline int INV(int x){
    if(x&1){
        x>>=1;
        x+=1;
        return -x;
    }else{
        return (x>>1)+1;
    }
}
//VARで作った変数の否定表現を取り出す
inline int NOT(int x){
    return x^1;
}
std::vector<std::pair<int,int>> inp;
int main(){
    std::set<int> ans;
    std::cin>>V>>E;//変数の数とClauseの数を入力に入れる
    V*=2;
    graph.resize(V);
    for(long long i = 0; i < E; i++){
        //入力は絶対値が変数の区別、負の値かどうかでその制約が否定かどうかを表す
        int tmp1,tmp2;
        scanf("%d %d\n",&tmp1,&tmp2);
        inp.push_back(std::make_pair(tmp1,tmp2));
        tmp1=VAR(tmp1);
        tmp2=VAR(tmp2);
        graph[NOT(tmp1)].push_back(tmp2);
        graph[NOT(tmp2)].push_back(tmp1);
    }
    //ここまで入力処理
    auto g=strongly_connected();//結果はすでにトポロジカルソートされている
    //強連結成分の中に矛盾がないか探す
    for (auto &&i : g)
    {
        for(long long j = 1; j < i.size(); j++){
            if(NOT(i[j])==i[j-1]){
                goto NOTHING;
            }
        }
        std::reverse(i.begin(),i.end());
    }
    std::reverse(g.begin(),g.end());
    //順番を入れ替えて否定かそのままか最初に出た表現を答えとする
    for (auto &&i : g)
    {
        for (auto &&j : i)
        {
            if(ans.count(j)==0&&ans.count(NOT(j))==0){
                ans.insert(j);
            }
        }
    }
    for (auto &&i : ans)
    {
        printf("%d ",INV(i));
    }
    for (auto &&i : inp)
    {
        assert(ans.count(VAR(i.first))||ans.count(VAR(i.second)));
    }
    puts("");
    return 0;
    NOTHING:
    std::cout<<"No answer"<<std::endl;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/stronglyconnected.cpp"
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<iostream>
#include<set>
#include<utility>
#include<assert.h>
#ifdef ENABLE_DEBUG
#define dump(a) std::cerr<<#a<<"="<<a<<std::endl
#define dumparr(a,n) std::cerr<<#a<<"["<<n<<"]="<<a[n]<<std::endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
std::vector<std::vector<int>> graph;
std::vector<bool> used;
std::vector<int> order;
std::vector<int> group;
std::vector<std::vector<int>> t;
std::vector<std::vector<int>> rev_graph(graph.size());
void dfs(int i){
    if(used[i]==true){
        return;
    }
    used[i]=true;
    for (auto &&to : graph[i])
    {
        dfs(to);
    }
    order.push_back(i);
}
void rdfs(int idx,int g){
    if(group[idx]!=-1)return;
    group[idx]=g;
    for (auto &&to : rev_graph[idx])
    {
        rdfs(to,g);
    }
    
}
std::vector<std::vector<int>> strongly_connected(){
    used.resize(graph.size());
    fill(used.begin(),used.end(),false);
    group.resize(graph.size());
    rev_graph.resize(graph.size());
    for(int i=0;i<graph.size();i++){
        if(used[i]==false){
            dfs(i);
        }
    }
    for (int i=0;i<graph.size();i++)
    {
        for (auto &&j : graph[i])
        {
            rev_graph[j].push_back(i);
        }
    }
    std::fill(group.begin(),group.end(),-1);
    int g=0;
    reverse(order.begin(),order.end());
    for (auto &&i : order)
    {
        if(group[i]!=-1)continue;
        rdfs(i,g++);
    }
    t.resize(g);
    for(long long i = 0; i < group.size(); i++){
        t[group[i]].push_back(i);        
    }
    return t;
}
int V,E;
//ソートしたときに変数とその否定が連続するように2倍して偶奇で否定がついているかどうかを見分ける形にする
inline int VAR(int x){
    if(x<0){
        x=-x;
        x-=1;
        x<<=1;
        x+=1;
    }else{
        x-=1;
        x<<=1;
    }
    return x;
}
//VARの逆関数、出力用
inline int INV(int x){
    if(x&1){
        x>>=1;
        x+=1;
        return -x;
    }else{
        return (x>>1)+1;
    }
}
//VARで作った変数の否定表現を取り出す
inline int NOT(int x){
    return x^1;
}
std::vector<std::pair<int,int>> inp;
int main(){
    std::set<int> ans;
    std::cin>>V>>E;//変数の数とClauseの数を入力に入れる
    V*=2;
    graph.resize(V);
    for(long long i = 0; i < E; i++){
        //入力は絶対値が変数の区別、負の値かどうかでその制約が否定かどうかを表す
        int tmp1,tmp2;
        scanf("%d %d\n",&tmp1,&tmp2);
        inp.push_back(std::make_pair(tmp1,tmp2));
        tmp1=VAR(tmp1);
        tmp2=VAR(tmp2);
        graph[NOT(tmp1)].push_back(tmp2);
        graph[NOT(tmp2)].push_back(tmp1);
    }
    //ここまで入力処理
    auto g=strongly_connected();//結果はすでにトポロジカルソートされている
    //強連結成分の中に矛盾がないか探す
    for (auto &&i : g)
    {
        for(long long j = 1; j < i.size(); j++){
            if(NOT(i[j])==i[j-1]){
                goto NOTHING;
            }
        }
        std::reverse(i.begin(),i.end());
    }
    std::reverse(g.begin(),g.end());
    //順番を入れ替えて否定かそのままか最初に出た表現を答えとする
    for (auto &&i : g)
    {
        for (auto &&j : i)
        {
            if(ans.count(j)==0&&ans.count(NOT(j))==0){
                ans.insert(j);
            }
        }
    }
    for (auto &&i : ans)
    {
        printf("%d ",INV(i));
    }
    for (auto &&i : inp)
    {
        assert(ans.count(VAR(i.first))||ans.count(VAR(i.second)));
    }
    puts("");
    return 0;
    NOTHING:
    std::cout<<"No answer"<<std::endl;
    return 0;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

