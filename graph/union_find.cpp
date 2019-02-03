#include<bits/stdc++.h>
using namespace std;
class UF{
  vector<int> par,rank;
public:
  UF(int size){
    for (int i = 0; i < size; i++) {
      par.push_back(i);
      rank.push_back(0);
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
    if(rank[x]<rank[y])par[x]=y;
    else{
      par[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
};
