#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "datastructure/SegmentTree.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long n,q;
    cin>>n>>q;
    function<long(long,long)> f = [](long a,long b){return a+b;};
    segtree<long> st(f,0L,n);
    for (size_t i = 0; i < q; i++)
    {
        long com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            --x;
            st.add_val(x,y);
        }else{
            --x;
            cout<<st.query(x,y)<<endl;
        }
    }
    
    return 0;
}
