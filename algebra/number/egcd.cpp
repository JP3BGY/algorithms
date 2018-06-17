template<typename T> 
int sgn(T val){
  return (T(0)<val)-(val<T(0));
}

tuple<long long,long long,long long> egcd(long long a,long long b){
  if(a==0||b==0)return std::make_tuple(0LL,0LL,0LL);
  long long sa=sgn(a),sb=sgn(b);
  a=std::abs(a);b=std::abs(b);
  long long p=1,q=0,r=0,s=1;
  while(b>0){
    long long c=a/b;
    long long d;
    d=a;a=b;b=d%b;
    d=p;p=q;q=d-c*q;
    d=r;r=s;s=d-c*s;
  }
  return std::make_tuple(a,p*sa,r*sb);
}


