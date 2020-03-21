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


# :warning: geometry/geometry.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-22 00:38:02+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
typedef std::complex<long double> point;
typedef struct {point p;long double r;} circle;

std::vector<point> circle_cross(const circle &a,const circle &b){
    long double d = abs(a.p-b.p);
    if(d>a.r+b.r||abs(a.r-b.r)>d||(a.p==b.p&&a.r==b.r)){
        return std::vector<point>(0);
    }
    long double rc = (d*d+a.r*a.r-b.r*b.r)/(2*d);
    long double rs = sqrtl(a.r*a.r-rc*rc);
    point diff = (b.p-a.p)/d;
    return std::vector<point> {a.p+diff*point(rc,rs),a.p+diff*point(rc,-rs)};
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "geometry/geometry.cpp"
#include<bits/stdc++.h>
typedef std::complex<long double> point;
typedef struct {point p;long double r;} circle;

std::vector<point> circle_cross(const circle &a,const circle &b){
    long double d = abs(a.p-b.p);
    if(d>a.r+b.r||abs(a.r-b.r)>d||(a.p==b.p&&a.r==b.r)){
        return std::vector<point>(0);
    }
    long double rc = (d*d+a.r*a.r-b.r*b.r)/(2*d);
    long double rs = sqrtl(a.r*a.r-rc*rc);
    point diff = (b.p-a.p)/d;
    return std::vector<point> {a.p+diff*point(rc,rs),a.p+diff*point(rc,-rs)};
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

