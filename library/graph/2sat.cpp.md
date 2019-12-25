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


# :warning: graph/2sat.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/2sat.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cstdio>
#include <random>
using namespace std;
int main(int argc, char const* argv[])
{
  random_device rng;
  uniform_int_distribution<size_t> dist(1,1000000);
  int V=dist(rng),E=dist(rng);
  printf("%d %d\n",V,E);
  fprintf(stderr, "%d %d\n",V,E);
  uniform_int_distribution<size_t> dist2(1,V),distpm(0,1);
  for (int i = 0; i < E; i++) {
    int p=dist2(rng),q=dist2(rng);
    if(distpm(rng)==0){
      p=-p;
    }
    if(distpm(rng)==0){
      q=-q;
    }
    printf("%d %d\n",p,q);
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/2sat.cpp"
#include <cstdio>
#include <random>
using namespace std;
int main(int argc, char const* argv[])
{
  random_device rng;
  uniform_int_distribution<size_t> dist(1,1000000);
  int V=dist(rng),E=dist(rng);
  printf("%d %d\n",V,E);
  fprintf(stderr, "%d %d\n",V,E);
  uniform_int_distribution<size_t> dist2(1,V),distpm(0,1);
  for (int i = 0; i < E; i++) {
    int p=dist2(rng),q=dist2(rng);
    if(distpm(rng)==0){
      p=-p;
    }
    if(distpm(rng)==0){
      q=-q;
    }
    printf("%d %d\n",p,q);
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
