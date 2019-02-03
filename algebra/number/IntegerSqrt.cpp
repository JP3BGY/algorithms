#ifndef INTEGERSQRT
#define INTEGERSQRT
long long intSqrt(long long x){
  if(x<0)return -1;
  long long a = 0, c = 0, y = 0, i = 0, t = x;
  while(t >>= 1){
    ++i;
  }
  for(i += i & 1; i >= 0; i -= 2){
    c = (y << 1 | 1) <= x >> i;
    a = a << 1 | c;
    y = y << 1 | c;
    x -= c * y << i;
    /* if(c){
      x -= y << i;
    } */
    y += c;
  }
  return a;
}
#endif
