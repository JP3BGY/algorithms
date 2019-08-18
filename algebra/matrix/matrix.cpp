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