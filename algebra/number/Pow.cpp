template<typename T>
T modpow(T a,unsigned long long b,unsigned long long MOD){
  T base=a,ans=T(1LL);
  while(b){
    if(b&1){
      ans=ans*base%MOD;
    }
    base=base*base%MOD;
    b>>=1;
  }
  return ans;
}
