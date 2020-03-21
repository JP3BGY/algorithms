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