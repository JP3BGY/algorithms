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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: fuzzer/test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#dc353651dacf3fd969bc27be2431b98b">fuzzer</a>
* <a href="{{ site.github.repository_url }}/blob/master/fuzzer/test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
 
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;
 
const ll INF=(1LL<<50);
ll gcd(ll a,ll b){
    a=abs(a);
    b=abs(b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
set<ll> p,ansp;
void solve(long long N, std::vector<long long> a){
    ll g=a[0];
    for (auto &&i : a)
    {
        g=gcd(i,g);
    }
    for(long long i = 0; i < a.size(); i++){
        a[i]/=g;
    }
    ll zero=a.back(),sum=accumulate(a.begin(),a.end(),0),summ=0;
    for(long long i = 0; i < a.size(); i++){
        if(i%2==0){
            summ+=a[a.size()-1-i];
        }else{
            summ-=a[a.size()-1-i];
        }
    }
    ll ans=gcd(zero,sum);
    ans=gcd(ans,summ);
    for(long long i = 2; i*i <= ans&&ans > 1; i+=2){
        if(ans%i==0){
            while(ans%i==0)ans/=i;
            p.insert(i);
        }
        if(i==2)i--;
    }
    if(ans!=1)p.insert(ans);
    for (auto &&i : p)
    {
        vector<ll> sums;
        sums.resize(i-1);
        for(long long j = 0; j < a.size(); j++){
            sums[j%(i-1)]+=a[j];
            sums[j%(i-1)]%=i;
        }
        bool flag=true;
        for (auto &&j : sums)
        {
            if(j%i!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            ansp.insert(i);
        }
    }
    for(long long i = 2; i*i <= g&&g > 1; i+=2){
        if(g%i==0){
            while(g%i==0)g/=i;
            ansp.insert(i);
        }
        if(i==2)i--;
    }
    if(g!=1)ansp.insert(g);
    for (auto &&i : ansp)
    {
        cout<<i<<endl;
    }
    
    
}
 
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-0+1);
    for(int i = 0 ; i < N-0+1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "fuzzer/test.cpp"
#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
 
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;
 
const ll INF=(1LL<<50);
ll gcd(ll a,ll b){
    a=abs(a);
    b=abs(b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
set<ll> p,ansp;
void solve(long long N, std::vector<long long> a){
    ll g=a[0];
    for (auto &&i : a)
    {
        g=gcd(i,g);
    }
    for(long long i = 0; i < a.size(); i++){
        a[i]/=g;
    }
    ll zero=a.back(),sum=accumulate(a.begin(),a.end(),0),summ=0;
    for(long long i = 0; i < a.size(); i++){
        if(i%2==0){
            summ+=a[a.size()-1-i];
        }else{
            summ-=a[a.size()-1-i];
        }
    }
    ll ans=gcd(zero,sum);
    ans=gcd(ans,summ);
    for(long long i = 2; i*i <= ans&&ans > 1; i+=2){
        if(ans%i==0){
            while(ans%i==0)ans/=i;
            p.insert(i);
        }
        if(i==2)i--;
    }
    if(ans!=1)p.insert(ans);
    for (auto &&i : p)
    {
        vector<ll> sums;
        sums.resize(i-1);
        for(long long j = 0; j < a.size(); j++){
            sums[j%(i-1)]+=a[j];
            sums[j%(i-1)]%=i;
        }
        bool flag=true;
        for (auto &&j : sums)
        {
            if(j%i!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            ansp.insert(i);
        }
    }
    for(long long i = 2; i*i <= g&&g > 1; i+=2){
        if(g%i==0){
            while(g%i==0)g/=i;
            ansp.insert(i);
        }
        if(i==2)i--;
    }
    if(g!=1)ansp.insert(g);
    for (auto &&i : ansp)
    {
        cout<<i<<endl;
    }
    
    
}
 
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-0+1);
    for(int i = 0 ; i < N-0+1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

