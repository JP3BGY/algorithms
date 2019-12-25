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


# :warning: algebra/number/Pow.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eff53351317ed5e83ba9ff9cfd3cdf3c">algebra/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/number/Pow.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Required by

* :warning: <a href="BabyStepGiantStep.cpp.html">algebra/number/BabyStepGiantStep.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T>
T modpow(T a,unsigned long long b,unsigned long long MOD){
  T base=a,ans=T(1LL);
  while(b){
    if(b&1){
      ans=ans*base%MOD;
    }
    base=base*base%MOD;
    b>>=1;
  }
  return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/number/Pow.cpp"
template<typename T>
T modpow(T a,unsigned long long b,unsigned long long MOD){
  T base=a,ans=T(1LL);
  while(b){
    if(b&1){
      ans=ans*base%MOD;
    }
    base=base*base%MOD;
    b>>=1;
  }
  return ans;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

