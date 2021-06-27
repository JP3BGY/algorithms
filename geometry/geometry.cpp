#include<bits/stdc++.h>
typedef std::complex<long double> point;
typedef struct {point p;long double r;} circle;

std::vector<point> circle_cross(const circle &a,const circle &b){
    long double d = abs(a.p-b.p);
    if(d>a.r+b.r||abs(a.r-b.r)>d||(a.p==b.p&&a.r==b.r)){
        return std::vector<point>(0);
    }
    long double rc = (d*d+a.r*a.r-b.r*b.r)/(2*d);
    long double rs = sqrtl(a.r*a.r-rc*rc);
    point diff = (b.p-a.p)/d;
    return std::vector<point> {a.p+diff*point(rc,rs),a.p+diff*point(rc,-rs)};
}
std::pair<long long,long long> direction(std::pair<long long,long long> x){
  long long tmp=std::gcd(x.first,x.second);
  x.first/=tmp;
  x.second/=tmp;
  if(x.first<0||(x.first==0&&x.second<0)){
    x.first=-x.first;
    x.second=-x.second;
  }
  return x;
}
long long dist(std::pair<long long,long long> x,std::pair<long long,long long> y=pair<long long,long long>(0,0)){
  using namespace std;
  long long dx=abs(x.first-y.first),dy=abs(x.second-y.second);
  return dx*dx+dy*dy;
}
long long dot(std::pair<long long,long long> x,std::pair<long long,long long> y){
  using namespace std;
  return x.first*y.first+x.second*y.second;
}
long long cross(std::pair<long long,long long> x,std::pair<long long,long long> y){
  using namespace std;
  return x.first*y.second-x.second*y.first;
}
bool atan2_cmp (std::pair<long long,long long> l,std::pair<long long,long long> r){
	long double atl=atan2l((long double)l.second,(long double)l.first);
	long double atr=atan2l((long double)r.second,(long double)r.first);
	return (atl!=atr)?(atl<atr):((l.first*l.first+l.second*l.second)<(r.first*r.first+r.second*r.second));
}
bool arg_cmp (std::pair<long long,long long> x,std::pair<long long,long long> y){
  // (-π,π]で、角度が大きい方がtrue（ソートすると前に来る）、角度が同じなら長さが長い方がtrue
  using namespace std;
  assert(!(x.first==0&&x.second==0));
  assert(!(y.first==0&&y.second==0));
  if(cross(x,y)==0&&dot(x,y)>0){
    return dist(x)>dist(y);
  }
  if(x.second==0&&y.second==0){
    return x.first<0;
  }
  if(x.second>=0&&y.second<0){
    return true;
  }
  if(x.second<0&&y.second>=0){
    return false;
  }
  return cross(x,y)<0;
}