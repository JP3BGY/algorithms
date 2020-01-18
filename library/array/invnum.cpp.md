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


# :warning: array/invnum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1f713c9e000f5d3f280adbd124df4f5">array</a>
* <a href="{{ site.github.repository_url }}/blob/master/array/invnum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-19 01:00:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<class ITR>
long long inv_num(ITR b,ITR e){
    using T = typeof(*b);
    ll ret=0;
    __gnu_pbds::tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> s;
    while(b!=e){
        ret+=s.size()-s.order_of_key(*b);
        ++b;
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "array/invnum.cpp"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<class ITR>
long long inv_num(ITR b,ITR e){
    using T = typeof(*b);
    ll ret=0;
    __gnu_pbds::tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> s;
    while(b!=e){
        ret+=s.size()-s.order_of_key(*b);
        ++b;
    }
    return ret;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

