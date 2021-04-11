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
#endif