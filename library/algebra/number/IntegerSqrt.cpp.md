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


# :warning: algebra/number/IntegerSqrt.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#eff53351317ed5e83ba9ff9cfd3cdf3c">algebra/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/number/IntegerSqrt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-02-03 18:42:50+09:00




## Required by

* :warning: <a href="BabyStepGiantStep.cpp.html">algebra/number/BabyStepGiantStep.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INTEGERSQRT
#define INTEGERSQRT
long long intSqrt(long long x){
  if(x<0)return -1;
  long long a = 0, c = 0, y = 0, i = 0, t = x;
  while(t >>= 1){
    ++i;
  }
  for(i += i & 1; i >= 0; i -= 2){
    c = (y << 1 | 1) <= x >> i;
    a = a << 1 | c;
    y = y << 1 | c;
    x -= c * y << i;
    /* if(c){
      x -= y << i;
    } */
    y += c;
  }
  return a;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/number/IntegerSqrt.cpp"


long long intSqrt(long long x){
  if(x<0)return -1;
  long long a = 0, c = 0, y = 0, i = 0, t = x;
  while(t >>= 1){
    ++i;
  }
  for(i += i & 1; i >= 0; i -= 2){
    c = (y << 1 | 1) <= x >> i;
    a = a << 1 | c;
    y = y << 1 | c;
    x -= c * y << i;
    /* if(c){
      x -= y << i;
    } */
    y += c;
  }
  return a;
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

