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


# :warning: datastructure/bit.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/bit.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
inline long long LSB(long long a){
    return a & -a;
}
class BIT{
    std::vector<long long> bit;
    int n;
public:
    BIT(int n):n(n){
        bit=std::vector<long long>(n,0);
    }

    void add(int a,long long b){
        a++;
        for(long long i = a; i <= n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
};
class LazyBIT{
    std::vector<long long> bit;
    std::vector<long long> lazy;
    std::set<int> s;
    int n;
public:
    LazyBIT(int n):n(n){
        bit=std::vector<long long>(n,0);
        lazy=std::vector<long long>(n,0);
        s=std::set<int>();           
    }
    void add(int a,long long b){
        if(a<0||a>=n)return;
        lazy[a]+=b;
        s.insert(a);
    }
    void lazyadd(int a,long long b){
        a++;
        for(long long i = a; i < n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(s.size()){
            for(auto&& i : s)
            {
                lazyadd(i,lazy[i]);
            }
            s.clear();
        }
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
    long long operator [](int a){
        if(a<0||a>n)exit(1);
        return get(a);
    }
    int lowerBound(int w){
        if(w<=0)return 0;
        
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/bit.cpp"
#include <bits/stdc++.h>
inline long long LSB(long long a){
    return a & -a;
}
class BIT{
    std::vector<long long> bit;
    int n;
public:
    BIT(int n):n(n){
        bit=std::vector<long long>(n,0);
    }

    void add(int a,long long b){
        a++;
        for(long long i = a; i <= n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
};
class LazyBIT{
    std::vector<long long> bit;
    std::vector<long long> lazy;
    std::set<int> s;
    int n;
public:
    LazyBIT(int n):n(n){
        bit=std::vector<long long>(n,0);
        lazy=std::vector<long long>(n,0);
        s=std::set<int>();           
    }
    void add(int a,long long b){
        if(a<0||a>=n)return;
        lazy[a]+=b;
        s.insert(a);
    }
    void lazyadd(int a,long long b){
        a++;
        for(long long i = a; i < n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(s.size()){
            for(auto&& i : s)
            {
                lazyadd(i,lazy[i]);
            }
            s.clear();
        }
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
    long long operator [](int a){
        if(a<0||a>n)exit(1);
        return get(a);
    }
    int lowerBound(int w){
        if(w<=0)return 0;
        
    }
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

