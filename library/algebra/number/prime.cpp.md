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


# :warning: algebra/number/prime.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eff53351317ed5e83ba9ff9cfd3cdf3c">algebra/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/number/prime.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef PRIME
#define PRIME
#include<bits/stdc++.h>
std::vector<long long> primes(long long a){
    std::vector<long long> ret;
    for(long long i = 2; i <= a; i+=2){
        bool flag=true;
        for(auto&& j : ret)
        {
            if(i%j==0){
                flag=false;
            }
        }
        if(flag){
            ret.push_back(i);
        }
        if(i==2){
            i--;
        }
    }
    return move(ret);
}
#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/number/prime.cpp"


#include<bits/stdc++.h>
std::vector<long long> primes(long long a){
    std::vector<long long> ret;
    for(long long i = 2; i <= a; i+=2){
        bool flag=true;
        for(auto&& j : ret)
        {
            if(i%j==0){
                flag=false;
            }
        }
        if(flag){
            ret.push_back(i);
        }
        if(i==2){
            i--;
        }
    }
    return move(ret);
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
