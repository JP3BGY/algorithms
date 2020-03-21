#include<bits/stdc++.h>
using namespace std;
class UF{
  vector<long> par,rank,size_uf;
  long _chunk_size;
public:
  UF(long size):_chunk_size(size){
    for (long i = 0; i < size; i++) {
      par.push_back(i);
      rank.push_back(0);
      size_uf.push_back(1);
    }
  }
  long find(long x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  void unite(long x,long y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    --_chunk_size;
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
  bool same(long x,long y){
    return find(x)==find(y);
  }
  long operator [](long x){
    return this->find(x);
  }
  long size(long x){
    x=find(x);
    return size_uf[x];
  }
  long chunk_size(){
    return this->_chunk_size;
  }
};
