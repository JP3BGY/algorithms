#ifndef BSGS
#define BSGS
#include "Modulo.cpp"
#include "Pow.cpp"
#include "IntegerSqrt.cpp"
template<long long m>
Modulo<m> bsgs(Modulo<m> g,Modulo<m> a){
  long long n=intSqrt((long long)a-1)+1;
  Modulo<m> inv=Modulo<m>(1)/pow(g,(unsigned long long)n);
  map<Modulo<m>,long long> s;
  Modulo<m> tmp=1;
  for (long long i = 0; i < n; i++) {
    if(s.count(tmp)){
      break;
    }
    s[tmp]=i;
    tmp=tmp*g;
  }
  tmp=1;
  for (long long  i = 0; i < n; i++) {
    if(s.count(a*tmp)){
      return s[a*tmp]+n*i;
    }
    tmp=tmp*inv;
  }
  return m-1LL;
}
#endif

