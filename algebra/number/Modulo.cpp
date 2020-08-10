#ifndef MODULO
#define MODULO
#include<bits/stdc++.h>
#include"egcd.cpp"
#define MAX_N 100000
using namespace std;
long long cachedEulerPhi(long long n){
  static long long lookup=0,p[MAX_N],f[MAX_N];
  if(!lookup){
    fill(p,p+MAX_N,1);
    iota(f,f+MAX_N,0);
    for (long long i = 2; i < MAX_N; i++) {
      if(p[i]){
        f[i]-=f[i]/i;
        for (long long j = i+i; j < MAX_N; j+=i) {
          p[j]=0,f[j]-=f[j]/i;
        }
      }
    }
    lookup=1;
  }
  return f[n];
}


long long eulerPhi(long long n){
  if(n==0)return 0;
  static map<long long,long long> cache;
  if(cache.count(n))return cache[n];
  long long ans=n;
  for (long long i = 2; i*i <= n; i++) {
    if(n%i==0){
      ans-=ans/i;
      while(n%i==0)n/=i;
    }
  }
  if(n>1)ans-=ans/n;
  cache[n]=ans;
  return ans;
}
long long inverse(long long a,long long m){
  static map<long long,long long> cache;
  if(cache.count(a)>0){
    return cache[a];
  }
  auto b=egcd(a,m);
  if(std::get<0>(b)!=1)return 0;
  cache[a]=(std::get<1>(b)<0)?std::get<1>(b)+m:std::get<1>(b);
  return cache[a];
}
template<long long m>
class Modulo{
  long long a;
public:
  Modulo(){
    a=0;
  }
  Modulo(const long long b){
    a=(b%m+m)%m;
  }
  Modulo(const Modulo& b){
    a=b.a;
  }
  Modulo &operator = (const long long b){
    a=(b%m+m)%m;
    return *this;
  }
  Modulo &operator = (const Modulo& b){
    a=b.a;
    return *this;
  }
  Modulo operator + (const Modulo<m> &b)const{
    return {(a+b.a)%m};
  }
  Modulo operator - (const Modulo<m> &b)const{
    return {(a-b.a+m)%m};
  }
  Modulo operator * (const Modulo<m> &b)const{
    return {(a*b.a)%m};
  }
  Modulo operator / (const Modulo<m> &b)const{
    return {(a*inverse(b,m))%m};
  }
  Modulo operator + (const long long b)const{
    return {(a+b)%m};
  }
  Modulo operator - (const long long b)const{
    return {((a-b)%m+m)%m};
  }
  Modulo operator * (const long long b)const{
    return {(a*b)%m};
  }
  Modulo operator / (const long long b)const{
    return {(a*inverse(b%m,m))%m};
  }
  Modulo operator += (const Modulo<m> &b){
    this->a=(a+b.a)%m;
    return {(a+b.a)%m};
  }
  Modulo operator -= (const Modulo<m> &b){
    this->a=(a-b.a+m)%m;
    return {(a-b.a+m)%m};
  }
  Modulo operator *= (const Modulo<m> &b){
    this->a=(a*b.a)%m;
    return {(a*b.a)%m};
  }
  Modulo operator /= (const Modulo<m> &b){
    this->a=(a*inverse(b,m))%m;
    return {(a*inverse(b,m))%m};
  }
  Modulo operator += (const long long b){
    this->a=(a+b)%m;
    return {(a+b)%m};
  }
  Modulo operator -= (const long long b){
    this->a=((a-b)%m+m)%m;
    return {((a-b)%m+m)%m};
  }
  Modulo operator *= (const long long b){
    this->a=(a*b)%m;
    return {(a*b)%m};
  }
  Modulo operator /= (const long long b){
    this->a=(a*inverse(b%m,m))%m;
    return {(a*inverse(b%m,m))%m};
  }
  Modulo operator < (const Modulo<m> &b)const{
    return a<b.a;
  }
  Modulo operator > (const Modulo<m> &b)const{
    return a>b.a;
  }
  operator long long() const{return a;}
};
template<long long m>
std::ostream& operator<<(std::ostream& os,Modulo<m> a){
  os<<(long long)(a);
  return os;
}

template<long long m>
Modulo<m> modpow(Modulo<m> a,long long b){
  long long c;
  long long mod_pow=eulerPhi(m);
  if(b>64){
    c=64%mod_pow;
    b=b%mod_pow;
    if(c>b){
      b=b+mod_pow;
    }
    c=64+(b-c);
  }else{
    c=b;
  }
  b=c;
  Modulo<m> base=a,ans=Modulo<m>(1LL);
  while(b){
    if(b&1){
      ans=ans*base;
    }
    base=base*base;
    b>>=1;
  }
  return ans;
}
#endif
