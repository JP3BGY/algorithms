#include<bits/stdc++.h>

template<int N,class T>
struct Matrix{
  T mat[N][N];
  Matrix(){
    memset(mat,0,sizeof(mat));
  }
  Matrix(T diag){
    memset(mat,0,sizeof(mat));
    for(int i=0;i<N;i++){
      mat[i][i]=diag;
    }
  }
  Matrix(const Matrix<N,T> &c){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        mat[i][j]=c.mat[i][j];
      }
    }
  }
  Matrix operator *(const Matrix &a) const{
    Matrix<N,T> ans=Matrix<N,T>();
    for(int k=0;k<N;k++){
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
          ans.mat[i][j]+=mat[i][k]*a.mat[k][j];
        }
      }
    }
    return ans;
  }
  Matrix mat_pow(long long t) const{
    Matrix<N,T> base=Matrix<N,T>(*this),ans=Matrix<N,T>();
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
