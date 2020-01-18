#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<class ITR>
long long inv_num(ITR b,ITR e){
    using T = typeof(*b);
    ll ret=0;
    __gnu_pbds::tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> s;
    while(b!=e){
        ret+=s.size()-s.order_of_key(*b);
        ++b;
    }
    return ret;
}