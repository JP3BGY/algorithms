#ifndef COMBINATION
#define COMBINATION
#include<bits/stdc++.h>
#include"egcd.cpp"
#include"Modulo.cpp"
using namespace std;
long long factorial(long long a,long long m){
  long long ret=1;
  for (long long i = 1; i <= a; i++) {
    ret*=(i%m);
    ret%=m;
  }
  return ret;
}
long long partial_factorial(long long a,long long n,long long m){
  long long ret=1;
  for (long long i = 0; i < n; i++) {
    ret*=(a-i)%m;
    ret%=m;
  }
  return ret;
}
long long combination_prime(long long n,long long r,long long m){
  long long ret;
  long long fact_r=factorial(r,m);
  ret=inverse(fact_r,m);
  long long pfact_n=partial_factorial(n,r,m);
  ret*=pfact_n;
  ret%=m;
  return ret;
}
const long long max_cache=1000000;
long long cache_fact[max_cache],cache_inv_fact[max_cache];
long long combination_cached(long long n,long long r,long long m=1000000007LL){
  static bool cached=false;
  if(cached==false){
    cached=true;
    cache_inv_fact[1]=1;
    for (long long i = 2; i < max_cache; i++) {
      cache_inv_fact[i]=(m-m/i)*cache_inv_fact[m%i]%m;
    }
    for (long long i = 2; i < max_cache; i++){
      cache_inv_fact[i]=cache_inv_fact[i]*cache_inv_fact[i-1]%m;
    }
    cache_fact[0]=1;
    for (long long i = 1; i < max_cache; i++) {
      cache_fact[i]=cache_fact[i-1]*i%m;
    }
  }
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
  if(n>m){
    std::cerr<<"Combination Error: n is greater than m"<<std::endl;
    exit(1);
  }
  r=min(r,n-r);
  return cache_fact[n]*cache_inv_fact[r]%m*cache_inv_fact[n-r]%m;
}
long long combination_mod_2(long long n,long long r){
  return n==(r|n-r);
}
long long homogeneous(long long n,long long r,long long m){
  return combination_prime(n+r-1,r,m);
}
#endif
