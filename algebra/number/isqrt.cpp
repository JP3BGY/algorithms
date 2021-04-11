#include<bits/stdc++.h>
long long isqrt(long long X){
  assert(X>=0);
  if(X==0)return 0;
  if(X==1)return 1;
  __int128_t l=1,r=X;
  while(l+1<r){
    __int128_t mid=(l+r)/2;
    if(mid*mid>X){
      r=mid;
    }else{
      l=mid;
    }
  }
  assert(l*l <= X && X < (l+1)*(l+1));
  return l;
}