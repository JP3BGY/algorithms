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


# :warning: graph/union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
class UF{
  vector<int> par,rank,size_uf;
public:
  UF(int size){
    for (int i = 0; i < size; i++) {
      par.push_back(i);
      rank.push_back(0);
      size_uf.push_back(1);
    }
  }
  int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      par[x]=y;
      size_uf[y]+=size_uf[x];
    }
    else{
      par[y]=x;
      size_uf[x]+=size_uf[y];
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  int operator [](int x){
    return this->find(x);
  }
  int size(int x){
    x=find(x);
    return size_uf[x];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/union_find.cpp"
#include<bits/stdc++.h>
using namespace std;
class UF{
  vector<int> par,rank,size_uf;
public:
  UF(int size){
    for (int i = 0; i < size; i++) {
      par.push_back(i);
      rank.push_back(0);
      size_uf.push_back(1);
    }
  }
  int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      par[x]=y;
      size_uf[y]+=size_uf[x];
    }
    else{
      par[y]=x;
      size_uf[x]+=size_uf[y];
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  int operator [](int x){
    return this->find(x);
  }
  int size(int x){
    x=find(x);
    return size_uf[x];
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

