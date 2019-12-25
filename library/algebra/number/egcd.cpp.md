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


# :warning: algebra/number/egcd.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eff53351317ed5e83ba9ff9cfd3cdf3c">algebra/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/number/egcd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-03 18:42:50+09:00




## Required by

* :warning: <a href="BabyStepGiantStep.cpp.html">algebra/number/BabyStepGiantStep.cpp</a>
* :warning: <a href="Combination.cpp.html">algebra/number/Combination.cpp</a>
* :warning: <a href="Modulo.cpp.html">algebra/number/Modulo.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef EGCD
#define EGCD
#include<bits/stdc++.h>
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
#endif


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/number/egcd.cpp"


#include<bits/stdc++.h>
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



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

