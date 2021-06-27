#ifndef MODULO
#define MODULO
#include<bits/stdc++.h>
#include"egcd.cpp"
#define MAX_N 100000
long long cachedEulerPhi(long long n){
  using namespace std;
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

#include"prime.cpp"
long long eulerPhi(long long n){
  using namespace std;
  if(n==0)return 0;
  static map<long long,long long> cache;
  if(cache.count(n))return cache[n];
  auto div=factor(n);
  long long ans=n;
  for(int bits=1;bits<(1<<(long)div.size());++bits){
    long long mul=1;
    for(int j=0;j<div.size();++j){
      if(bits>>j & 1)mul*=div[j].first;
    }
    ans+= n/mul*(__builtin_popcount(bits)%2?-1,1);
  }
  return ans;
}
long long inverse(long long a,long long m){
  using namespace std;
  assert(abs(gcd(a,m))==1LL);
  assert(a!=0);
  a%=m;
  auto [val,da,dm]=egcd(a,m);
  return (da%m+m)%m;
}
class Modulo{
public:
  long long a=0,m=1000000007LL;
  Modulo(){};
  Modulo(long long a):a(a){
  }
  Modulo(const long long b,long long m):m(m){
    a=(b%m+m)%m;
  }
  Modulo(const Modulo& b){
    this->a=b.a;
    this->m=b.m;
  }
  Modulo &operator = (const Modulo& b){
    a=b.a;
    return *this;
  }
  Modulo operator + (const Modulo &b)const{
    assert(b.m==this->m);
    return {(a+b.a)%m};
  }
  Modulo operator - (const Modulo &b)const{
    assert(b.m==this->m);
    return {(a-b.a+m)%m};
  }
  Modulo operator * (const Modulo &b)const{
    assert(b.m==this->m);
    return {(a*b.a)%m};
  }
  Modulo operator / (const Modulo &b)const{
    assert(b.m==this->m);
    return {(a*inverse(b,m))%m};
  }
  Modulo operator += (const Modulo &b){
    assert(b.m==this->m);
    this->a=(a+b.a)%m;
    return this->a;
  }
  Modulo operator -= (const Modulo &b){
    assert(b.m==this->m);
    this->a=(a-b.a+m)%m;
    return this->a;
  }
  Modulo operator *= (const Modulo &b){
    assert(b.m==this->m);
    this->a=(a*b.a)%m;
    return this->a;
  }
  Modulo operator /= (const Modulo &b){
    assert(b.m==this->m);
    this->a=(a*inverse(b,m))%m;
    return this->a;
  }
  Modulo operator < (const Modulo &b)const{
    assert(b.m==this->m);
    return a<b.a;
  }
  Modulo operator > (const Modulo &b)const{
    assert(b.m==this->m);
    return a>b.a;
  }
  Modulo operator <= (const Modulo &b)const{
    assert(b.m==this->m);
    return a<=b.a;
  }
  Modulo operator >= (const Modulo &b)const{
    assert(b.m==this->m);
    return a>=b.a;
  }
  Modulo operator == (const Modulo &b)const{
    assert(b.m==this->m);
    return a==b.a;
  }
  Modulo operator != (const Modulo &b)const{
    assert(b.m==this->m);
    return a!=b.a;
  }
  Modulo &operator = (const long long b){
    a=(b%m+m)%m;
    return *this;
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
  Modulo operator += (const long long b){
    this->a=(a+b)%m;
    return this->a;
  }
  Modulo operator -= (const long long b){
    this->a=((a-b)%m+m)%m;
    return this->a;
  }
  Modulo operator *= (const long long b){
    this->a=(a*b)%m;
    return this->a;
  }
  Modulo operator /= (const long long b){
    this->a=(a*inverse(b%m,m))%m;
    return this->a;
  }
  Modulo operator == (long long b)const{
    return a==(b%this->m);
  }
  Modulo operator != (long long b)const{
    return a!=(b%this->m);
  }
  operator long long() const{return a;}
};
Modulo operator + (const long long b,const Modulo x){
  long long a=x.a,m=x.m;
  return Modulo((a+b%m)%m,m);
}
Modulo operator - (const long long b,const Modulo x){
  long long a=x.a,m=x.m;
  return Modulo(((a-b)%m+m)%m,m);
}
Modulo operator * (const long long b,const Modulo x){
  long long a=x.a,m=x.m;
  return Modulo((a*b)%m,m);
}
Modulo operator / (const long long b,const Modulo x){
  long long a=x.a,m=x.m;
  return Modulo((a*inverse(b%m,m))%m,m);
}
std::ostream& operator<<(std::ostream& os,Modulo a){
  using namespace std;
  os<<(long long)(a);
  return os;
}

Modulo modpow(Modulo a,long long b){
  using namespace std;
  long long c;
  long long mod_pow=eulerPhi(a.m);
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
  Modulo base=a,ans=Modulo(1LL);
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
