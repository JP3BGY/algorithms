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

long long cache_cmb[1000000],cache_inv_fact[1000000];
bool cached=false;
long long combination_cached(long long n,long long r,long long m){
  if(cached==false){
    cached=true;
    cache_inv_fact[1]=1;
    for (long long i = 2; i <= n; i++) {
      cache_inv_fact[i]=(m-m/i)*cache_inv_fact[m%i]%m;
    }
    cache_cmb[0]=1;
    for (long long i = 1; i <= n/2; i++) {
      cache_cmb[i]=cache_cmb[i-1]*(n-i+1)%m*cache_inv_fact[i]%m;
    }
  }
  r=min(r,n-r);
  return cache_cmb[r];
}
#endif
