#include <bits/stdc++.h>
template <typename T>
class segtree{
    using F = function<T(T,T)>;
    int n;
    F f;
    T init;
    vector<T> tree;
    segtree(F f,T init,const vector<T> &v){
        this->init=init;
        n=1;
        while(n<v.size())n<<=1;
        tree.assign(n<<1,init)
        build(v);
    }
    segtree(F f,T init,int n_){
        vector<T> v(n_);
        segtree(f,init,v);
    }
    void build(const vector<T> &v){
        for(int i=0;i<v.size();++i;)tree[n+i]=v[i];
        for(int i=n-1;i;--i){
            tree[i]=f(tree[i*2],tree[i*2+1]);
        }
    }
    void set_val(int k,T x){
        tree[k+=n]=x;
        while(k>>=1){
            tree[k]=f(tree[k*2],tree[k*2+1]);
        }
    }
    T query(int a,int b){
        T vl=init,vr=init;
        for(int l=a+n,r=b+n;l<r;l/=2,r/=2){
            if(l&1)vl=f(vl,tree[++l]);
            if(r&1)vr=f(tree[--r],vr);
        }
        return f(vl,vr);
    }

}