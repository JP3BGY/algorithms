template<typename T>
T pow(T a,unsigned long long b){
  T base=a,ans=T(1LL);
  while(b){
    if(b&1){
      ans=ans*base;
    }
    base=base*base;
    b>>=1;
  }
  return ans;
}
