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
