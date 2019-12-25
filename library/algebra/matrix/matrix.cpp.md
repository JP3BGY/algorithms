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


# :warning: algebra/matrix/matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#690a7dbf7bb05b34b7e5c0e1eca638d4">algebra/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebra/matrix/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-18 11:19:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>

template<class T>
struct Matrix{
  public:
  vector<vector<T>> mat;
  Matrix(long long N):mat(N,vector<T>(N)){
  }
  Matrix(long long N,T diag):mat(N,vector<T>(N)){
    for(int i=0;i<N;i++){
      mat[i][i]=diag;
    }
  }
  Matrix(const Matrix<T> &c):mat(c.mat.size(),vector<T>(c.mat.size())){
    long long N=c.mat.size();
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        mat[i][j]=c.mat[i][j];
      }
    }
  }
  Matrix operator *(const Matrix &a) const{
    assert(a.mat.size()==mat.size());
    Matrix<T> ans=Matrix<T>(mat.size());
    long long N=mat.size();
    for(int k=0;k<N;k++){
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
          ans.mat[i][j]+=mat[i][k]*a.mat[k][j];
        }
      }
    }
    return ans;
  }
  vector<T> operator *(const vector<T> b)const{
    long long N=mat.size();
    vector<T> ret(N);
    for(long long i = 0; i < N; i++){
      ret[i]=std::inner_product(mat[i].begin(),mat[i].end(),b.begin(),0LL);
    }
    return move(ret);
  }
  Matrix mat_pow(long long t) const{
    long long N=mat.size();
    Matrix<T> base=Matrix<T>(*this),ans=Matrix<T>(N,1LL);
    while(t){
      if(t&1){
        ans=ans*base;
      }
      base=base*base;
      t>>=1;
    }
    return ans;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algebra/matrix/matrix.cpp"
#include<bits/stdc++.h>

template<class T>
struct Matrix{
  public:
  vector<vector<T>> mat;
  Matrix(long long N):mat(N,vector<T>(N)){
  }
  Matrix(long long N,T diag):mat(N,vector<T>(N)){
    for(int i=0;i<N;i++){
      mat[i][i]=diag;
    }
  }
  Matrix(const Matrix<T> &c):mat(c.mat.size(),vector<T>(c.mat.size())){
    long long N=c.mat.size();
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        mat[i][j]=c.mat[i][j];
      }
    }
  }
  Matrix operator *(const Matrix &a) const{
    assert(a.mat.size()==mat.size());
    Matrix<T> ans=Matrix<T>(mat.size());
    long long N=mat.size();
    for(int k=0;k<N;k++){
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
          ans.mat[i][j]+=mat[i][k]*a.mat[k][j];
        }
      }
    }
    return ans;
  }
  vector<T> operator *(const vector<T> b)const{
    long long N=mat.size();
    vector<T> ret(N);
    for(long long i = 0; i < N; i++){
      ret[i]=std::inner_product(mat[i].begin(),mat[i].end(),b.begin(),0LL);
    }
    return move(ret);
  }
  Matrix mat_pow(long long t) const{
    long long N=mat.size();
    Matrix<T> base=Matrix<T>(*this),ans=Matrix<T>(N,1LL);
    while(t){
      if(t&1){
        ans=ans*base;
      }
      base=base*base;
      t>>=1;
    }
    return ans;
  }
};
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

