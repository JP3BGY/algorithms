long long modpow(long long a,long long b,unsigned long long MOD){
  long long base=a,ans=(1LL);
  while(b){
    if(b&1){
      ans=ans*base%MOD;
    }
    base=base*base%MOD;
    b>>=1;
  }
  return ans;
}
long long powll(long long a,long long b){
  long long base=a,ans=(1LL);
  while(b){
    if(b&1){
      ans=ans*base;
    }
    base=base*base;
    b>>=1;
  }
  return ans;
}
long long invpow(long long a,unsigned long long MOD){
  return modpow(a,MOD-2,MOD);
}