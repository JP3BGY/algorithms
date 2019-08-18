#include <bits/stdc++.h>
inline long long LSB(long long a){
    return a & -a;
}
class BIT{
    std::vector<long long> bit;
    int n;
public:
    BIT(int n):n(n){
        bit=std::vector<long long>(n,0);
    }

    void add(int a,long long b){
        a++;
        for(long long i = a; i <= n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
};
class LazyBIT{
    std::vector<long long> bit;
    std::vector<long long> lazy;
    std::set<int> s;
    int n;
public:
    LazyBIT(int n):n(n){
        bit=std::vector<long long>(n,0);
        lazy=std::vector<long long>(n,0);
        s=std::set<int>();           
    }
    void add(int a,long long b){
        if(a<0||a>=n)return;
        lazy[a]+=b;
        s.insert(a);
    }
    void lazyadd(int a,long long b){
        a++;
        for(long long i = a; i < n; i+=LSB(i)){
            bit[i-1]+=b;
        }
    }
    long long sum(int a){
        if(s.size()){
            for(auto&& i : s)
            {
                lazyadd(i,lazy[i]);
            }
            s.clear();
        }
        if(a<0)return 0;
        if(a>=n)a=n-1;
        a++;
        long long ret=0;
        for(long long i = a; i > 0; i-=LSB(i)){
            ret+=bit[i-1];
        }
        return ret;
    }
    long long sum(int a,int b){
        // [a,b)
        --b;
        if(a==0)return sum(b);
        return sum(b)-sum(a-1);
    }
    long long get(int a){
        if(a==0)return sum(0);
        return sum(a)-sum(a-1);
    }
    long long operator [](int a){
        if(a<0||a>n)exit(1);
        return get(a);
    }
    int lowerBound(int w){
        if(w<=0)return 0;
        
    }
};