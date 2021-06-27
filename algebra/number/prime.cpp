#ifndef PRIME
#define PRIME
#include<bits/stdc++.h>
std::vector<long long> primes(long long a){
    std::vector<long long> ret;
    for(long long i = 2; i <= a; i+=2){
        bool flag=true;
        for(auto&& j : ret)
        {
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag){
            ret.push_back(i);
        }
        if(i==2){
            i--;
        }
    }
    return ret;
}
std::vector<std::pair<long long,long long>> factor(long long a){
    using namespace std;
    typedef long long ll;
    static bool cached=false;
    static vector<long long> prime_set;
    const long long MAX_CACHED_PRIME=100000;
    if(cached==false){
        cached=true;
        prime_set=primes(MAX_CACHED_PRIME);
    }
    vector<pair<ll,ll>> ret;
    for (auto &&i : prime_set)
    {
        if(a%i==0){
            pair<ll,ll> tmp(i,0);
            while(a%i==0){
                tmp.second++;
                a/=i;
            }
            ret.push_back(tmp);
        }
        if(i*i>a){
            break;
        }
    }
    if(a>1){
        ret.emplace_back(a,1);
    }
    return ret;
}
#endif