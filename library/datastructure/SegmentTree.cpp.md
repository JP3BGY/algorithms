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


# :warning: datastructure/SegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
template <typename T>
class segtree{
    using F = function<T(T,T)>;
    int n;
    F f;
    T init;
    vector<T> tree;
    segtree(F f,T init,const vector<T> &v){
        this->init=init;
        n=1;
        while(n<v.size())n<<=1;
        tree.assign(n<<1,init)
        build(v);
    }
    segtree(F f,T init,int n_){
        vector<T> v(n_);
        segtree(f,init,v);
    }
    void build(const vector<T> &v){
        for(int i=0;i<v.size();++i;)tree[n+i]=v[i];
        for(int i=n-1;i;--i){
            tree[i]=f(tree[i*2],tree[i*2+1]);
        }
    }
    void set_val(int k,T x){
        tree[k+=n]=x;
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    T query(int a,int b){
        T vl=init,vr=init;
        for(int l=a+n,r=b+n;l<r;l/=2,r/=2){
            if(l&1)vl=f(vl,tree[++l]);
            if(r&1)vr=f(tree[--r],vr);
        }
        return f(vl,vr);
    }

}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/SegmentTree.cpp"
#include <bits/stdc++.h>
template <typename T>
class segtree{
    using F = function<T(T,T)>;
    int n;
    F f;
    T init;
    vector<T> tree;
    segtree(F f,T init,const vector<T> &v){
        this->init=init;
        n=1;
        while(n<v.size())n<<=1;
        tree.assign(n<<1,init)
        build(v);
    }
    segtree(F f,T init,int n_){
        vector<T> v(n_);
        segtree(f,init,v);
    }
    void build(const vector<T> &v){
        for(int i=0;i<v.size();++i;)tree[n+i]=v[i];
        for(int i=n-1;i;--i){
            tree[i]=f(tree[i*2],tree[i*2+1]);
        }
    }
    void set_val(int k,T x){
        tree[k+=n]=x;
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    T query(int a,int b){
        T vl=init,vr=init;
        for(int l=a+n,r=b+n;l<r;l/=2,r/=2){
            if(l&1)vl=f(vl,tree[++l]);
            if(r&1)vr=f(tree[--r],vr);
        }
        return f(vl,vr);
    }

}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

