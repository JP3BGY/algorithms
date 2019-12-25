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


# :warning: test/datastructure/test-SegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd2863e470d2af8ee92181d6e8c27bbc">test/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/test-SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-25 09:27:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
#include <bits/stdc++.h>
using namespace std;
template<typename T>
vector<T> build_segtree(function<T(T,T)>f,T unit,const vector<T> &v){
    long n=1;
    while(n<v.size()){n<<=1;}
    vector<T> tree(n<<1,unit);
    for(size_t i=0;i<v.size();++i)tree[n+i]=v[i];
    if(n>0)for(size_t i=n-1;i;--i){
        tree[i]=f(tree[i*2],tree[i*2+1]);
    }
    return tree;
}
template <typename T>
class segtree{
    using F = function<T(T,T)>;
    long n;
    F f;
    T unit;
    vector<T> tree;
    public:
    segtree(F f,T unit,const vector<T> &v):f(f),unit(unit),tree(){
        tree=build_segtree(f,unit,v);
        n = tree.size()/2;
    }
    segtree(F f,T unit,size_t n_):segtree(f,unit,vector<T>(n_,unit)){
    }
    void build(const vector<T> &v){
        for(size_t i=0;i<v.size();++i)tree[n+i]=v[i];
        if(n>0)for(size_t i=n-1;i;--i){
            tree[i]=f(tree[i*2],tree[i*2+1]);
        }
    }
    void set_val(size_t k,T x){
        if(k>n){
            cerr<<"out of size"<<endl;
            exit(1);
        }
        tree[k+=n]=x;
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    void add_val(size_t k,T x){
        if(k>n){
            cerr<<"out of size"<<endl;
            exit(1);
        }
        k+=n;
        tree[k]=f(tree[k],x);
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    T query(size_t a,size_t b){
        T vl=unit,vr=unit;
        for(int l=a+n,r=b+n;l<r;l/=2,r/=2){
            if(l&1)vl=f(vl,tree[l++]);
            if(r&1)vr=f(tree[--r],vr);
        }
        return f(vl,vr);
    }
};

int main(int argc, char const *argv[])
{
    long n,q;
    cin>>n>>q;
    function<long(long,long)> f = [](long a,long b){return a+b;};
    segtree<long> st(f,0L,n);
    for (size_t i = 0; i < q; i++)
    {
        long com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            --x;
            st.add_val(x,y);
        }else{
            --x;
            cout<<st.query(x,y)<<endl;
        }
    }
    
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/test-SegmentTree.cpp"
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
#include <bits/stdc++.h>
using namespace std;
template<typename T>
vector<T> build_segtree(function<T(T,T)>f,T unit,const vector<T> &v){
    long n=1;
    while(n<v.size()){n<<=1;}
    vector<T> tree(n<<1,unit);
    for(size_t i=0;i<v.size();++i)tree[n+i]=v[i];
    if(n>0)for(size_t i=n-1;i;--i){
        tree[i]=f(tree[i*2],tree[i*2+1]);
    }
    return tree;
}
template <typename T>
class segtree{
    using F = function<T(T,T)>;
    long n;
    F f;
    T unit;
    vector<T> tree;
    public:
    segtree(F f,T unit,const vector<T> &v):f(f),unit(unit),tree(){
        tree=build_segtree(f,unit,v);
        n = tree.size()/2;
    }
    segtree(F f,T unit,size_t n_):segtree(f,unit,vector<T>(n_,unit)){
    }
    void build(const vector<T> &v){
        for(size_t i=0;i<v.size();++i)tree[n+i]=v[i];
        if(n>0)for(size_t i=n-1;i;--i){
            tree[i]=f(tree[i*2],tree[i*2+1]);
        }
    }
    void set_val(size_t k,T x){
        if(k>n){
            cerr<<"out of size"<<endl;
            exit(1);
        }
        tree[k+=n]=x;
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    void add_val(size_t k,T x){
        if(k>n){
            cerr<<"out of size"<<endl;
            exit(1);
        }
        k+=n;
        tree[k]=f(tree[k],x);
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    T query(size_t a,size_t b){
        T vl=unit,vr=unit;
        for(int l=a+n,r=b+n;l<r;l/=2,r/=2){
            if(l&1)vl=f(vl,tree[l++]);
            if(r&1)vr=f(tree[--r],vr);
        }
        return f(vl,vr);
    }
};

int main(int argc, char const *argv[])
{
    long n,q;
    cin>>n>>q;
    function<long(long,long)> f = [](long a,long b){return a+b;};
    segtree<long> st(f,0L,n);
    for (size_t i = 0; i < q; i++)
    {
        long com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            --x;
            st.add_val(x,y);
        }else{
            --x;
            cout<<st.query(x,y)<<endl;
        }
    }
    
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

