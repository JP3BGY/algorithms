#include<bits/stdc++.h>
#include"../number/Modulo.cpp"
template<class T>
class Matrix{
  std::vector<std::vector<T>> mat;
public:
  const long n,m;
  Matrix(size_t n,size_t m,T x=0):n(n),m(m)mat(n,vector<T>(m,x)){
  }
  void init(size_t n,size_t m,T x=0){
    mat.assign(n,vector<T>(m,x));
  }
  size_t size()const {return mat.size();}
  inline vector<T>& operator [](size_t i){return mat[i];}
  vector<vector<T>> operator*= (const Matrix<T>& x)const {
    assert(x.n==m);
    
  }
};
template <class T>
tuple<long long,vector<long long>> GaussJordan(Matrix<T> &A,bool is_extended = false){
  using namespace std;
  const long double EPS = 1e-10;
  size_t m = A.size(),n=A[0].size();
  long long rank=0;
  typedef long long ll;
  vector<ll> s(m);
  iota(s.begin(),s.end(),0LL);
  for (size_t col = 0; col < n; col++)
  {
    if(is_extended&&col==n-1)break;
    size_t pivot = m;
    T ma=EPS;
    for (size_t row = rank; row < m; row++)
    {
      if(abs(A[row][col])>ma){
        ma=abs(A[row][col]);
        pivot = row;
      }
    }
    if(pivot==m)continue;
    swap(A[pivot],A[rank]);
    swap(s[pivot],s[rank]);
    auto fac=A[rank][col];
    for (size_t col2 = 0; col2 < n; col2++)
    {
      A[rank][col2]/=fac;
    }
    for (size_t row = 0; row < m; row++)
    {
      if(row!=rank&&abs(A[row][col])>EPS){
        auto fac=A[row][col];
        for (size_t col2 = 0; col2 < n; col2++)
        {
          A[row][col2]-=A[rank][col2]*fac;
        }
      }
    }
    ++rank;
  }
  return make_tuple(rank,s);
}
template<>
tuple<long long,vector<long long>> GaussJordan<Modulo>(Matrix<Modulo> &A,bool is_extended){
  using namespace std;
  typedef long long ll;
  size_t m = A.size(),n=A[0].size();
  vector<ll> s(m);
  iota(s.begin(),s.end(),0LL);
  long long rank=0;
  for (size_t col = 0; col < n; col++)
  {
    if(is_extended&&col==n-1)break;
    size_t pivot = m;
    for (size_t row = rank; row < m; row++)
    {
      if(abs(A[row][col])!=0LL){
        pivot = row;
        break;
      }
    }
    if(pivot==m)continue;
    swap(A[pivot],A[rank]);
    swap(s[pivot],s[rank]);
    auto fac=A[rank][col];
    for (size_t col2 = 0; col2 < n; col2++)
    {
      A[rank][col2]/=fac;
    }
    for (size_t row = 0; row < m; row++)
    {
      if(row!=rank&&(A[row][col])!=0LL){
        auto fac=A[row][col];
        for (size_t col2 = 0; col2 < n; col2++)
        {
          A[row][col2]-=A[rank][col2]*fac;
        }
      }
    }
    ++rank;
  }
  return make_tuple(rank,s);
}

template<class T>
vector<T> linear_equation(Matrix<T> A,vector<T> b){
  using namespace std;
  typedef long long ll;
  const long double EPS = 1e-10;
  size_t m=A.size(),n=A[0].size();
  Matrix<T> M(m,n+1);
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      M[i][j]=A[i][j];
    }
    M[i][n]=b[i];
  }
  auto [rank,s] = GaussJordan(M,true);
  vector<T> res;
  for (size_t row = rank; row < m; row++)
  {
    if(abs(M[row][n])>EPS)return res;
  }
  res.assign(n,0);
  size_t j=0;
  for (size_t i = 0; i < rank; i++)
  {
    while(j<n&&M[i][j]<EPS){
      ++j;
    }
    res[j]=M[i][n];
  }
  vector<pair<ll,T>> sres(n);
  for (size_t i = 0; i < n; i++)
  {
    sres[i]=pair<ll,ll>(s[i],res[i]);
  }
  sort(sres.begin(),sres.end());
  for (size_t i = 0; i < n; i++)
  {
    res[i]=sres[i].second;
  }
  return res;
}
template<>
vector<Modulo> linear_equation(Matrix<Modulo> A,vector<Modulo> b){
  using namespace std;
  typedef Modulo T;
  typedef long long ll;
  size_t m=A.size(),n=A[0].size();
  Matrix<T> M(m,n+1);
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      M[i][j]=A[i][j];
    }
    M[i][n]=b[i];
  }
  auto [rank,s] = GaussJordan(M,true);
  vector<T> res;
  for (size_t row = rank; row < m; row++)
  {
    if((M[row][n])==0LL)return res;
  }
  res.assign(n,0);
  size_t j=0;
  for (size_t i = 0; i < rank; i++)
  {
    while(j<n&&M[i][j]==0LL){
      ++j;
    }
    res[j]=M[i][n];
  }
  vector<pair<ll,T>> sres(n);
  for (size_t i = 0; i < n; i++)
  {
    sres[i]=pair<ll,ll>(s[i],res[i]);
  }
  sort(sres.begin(),sres.end());
  for (size_t i = 0; i < n; i++)
  {
    res[i]=sres[i].second;
  }
  return res;
}
const size_t MAX_ROW=1000;
const size_t MAX_COL=1000;
class BitMatrix{
  size_t H,W;
public:
  bitset<MAX_COL>mat[MAX_ROW];
  BitMatrix(size_t m=1,size_t n=1):H(m),W(n){}
  inline bitset<MAX_COL>& operator [](size_t i){return mat[i];}
  size_t size(){return H;}
  size_t size2(){return W;}
};
tuple<long long,vector<long long>> GaussJordan(BitMatrix &A,bool is_extended=false){
  using namespace std;
  typedef long long ll;
  size_t m = A.size(),n=A.size2();
  vector<ll> s(m);
  iota(s.begin(),s.end(),0LL);
  long long rank=0;
  for (size_t col = 0; col < n; col++)
  {
    if(is_extended&&col==n-1)break;
    size_t pivot = m;
    for (size_t row = rank; row < m; row++)
    {
      if(abs(A[row][col])){
        pivot = row;
        break;
      }
    }
    if(pivot==m)continue;
    swap(A[pivot],A[rank]);
    swap(s[pivot],s[rank]);
    for (size_t row = 0; row < m; row++)
    {
      if(row!=rank&&(A[row][col])){
        A[row]^=A[rank];
      }
    }
    ++rank;
  }
  return make_tuple(rank,s);
}


template<class T>
struct SqMatrix{
  vector<vector<T>> mat;
  public:
  SqMatrix(long long N=1):mat(N,vector<T>(N)){
  }
  SqMatrix(long long N,T diag):mat(N,vector<T>(N)){
    for(int i=0;i<N;i++){
      mat[i][i]=diag;
    }
  }
  SqMatrix(const SqMatrix<T> &c):mat(c.mat.size(),vector<T>(c.mat.size())){
    long long N=c.mat.size();
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        mat[i][j]=c.mat[i][j];
      }
    }
  }
  SqMatrix operator *(const SqMatrix &a) const{
    assert(a.mat.size()==mat.size());
    SqMatrix<T> ans=SqMatrix<T>(mat.size());
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
  SqMatrix mat_pow(long long t) const{
    long long N=mat.size();
    SqMatrix<T> base=SqMatrix<T>(*this),ans=SqMatrix<T>(N,1LL);
    while(t){
      if(t&1){
        ans=ans*base;
      }
      base=base*base;
      t>>=1;
    }
    return ans;
  }
  inline vector<T>& operator [](size_t i){return mat[i];}
};