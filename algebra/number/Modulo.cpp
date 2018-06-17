long long inverse(long long a,long long m){
  auto b=egcd(a,m);
  if(std::get<0>(b)!=1)return 0;
  return (std::get<1>(b)<0)?std::get<1>(b)+m:std::get<1>(b);
}
