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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: algebra/number/Combination.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eff53351317ed5e83ba9ff9cfd3cdf3c">algebra/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/number/Combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-22 00:38:39+09:00




## Depends on

* :warning: <a href="Modulo.cpp.html">algebra/number/Modulo.cpp</a>
* :warning: <a href="egcd.cpp.html">algebra/number/egcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
long long combination_cached(long long n,long long r,long long m){
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/number/Combination.cpp"


#include<bits/stdc++.h>
#line 1 "algebra/number/egcd.cpp"


#line 4 "algebra/number/egcd.cpp"
using namespace std;
template<typename T> 
int sgn(T val){
  return (T(0)<val)-(val<T(0));
}

tuple<long long,long long,long long> egcd(long long a,long long b){
  if(a==0||b==0)return std::make_tuple(0LL,0LL,0LL);
  long long sa=sgn(a),sb=sgn(b);
  a=std::abs(a);b=std::abs(b);
  long long p=1,q=0,r=0,s=1;
  while(b>0){
    long long c=a/b;
    long long d;
    d=a;a=b;b=d%b;
    d=p;p=q;q=d-c*q;
    d=r;r=s;s=d-c*s;
  }
  return std::make_tuple(a,p*sa,r*sb);
}


#line 1 "algebra/number/Modulo.cpp"


#line 5 "algebra/number/Modulo.cpp"
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
  Modulo operator < (const Modulo<m> &b)const{
    return a<b.a;
  }
  Modulo operator > (const Modulo<m> &b)const{
    return a>b.a;
  }
  operator long long() const{return a;}
};

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

#line 6 "algebra/number/Combination.cpp"
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
long long combination_cached(long long n,long long r,long long m){
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
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
  r=min(r,n-r);
  return cache_fact[n]*cache_inv_fact[r]%m*cache_inv_fact[n-r]%m;
}
long long combination_mod_2(long long n,long long r){
  return n==(r|n-r);
}
long long homogeneous(long long n,long long r,long long m){
  return combination_prime(n+r-1,r,m);
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

