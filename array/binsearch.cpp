#include<functional>
template<class T>
T binsearch(T init_left,T init_right,T eps,std::function<bool(T)> f){
  //引数は共に解の範囲外の値を入れる
  using namespace std;
  T l=init_left,r=init_right;
  while(l+eps<r){
    T mid=(l+r)/2;
    if(f(mid)){
        l=mid;
    }else{
        r=mid;
    }
  }
  return l;//必ずinit_leftとの比較をして解なしを判定する
};