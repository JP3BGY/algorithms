
#include <vector>
#include <map>
#include <tuple>
#include <deque>
#include <array>
#include <bitset>
#include <queue>
#include <climits>
#include <cassert>
class flow{
    typedef long long cap_t;
    typedef long long cost_t;
public:
    virtual void add_vertex(size_t from, size_t to, long long cap, long long cost)=0;
    virtual void del_vertex(size_t from, size_t to, long long cap, long long cost)=0;
    virtual long long get_capacity(size_t from, size_t to,  long long cost)=0;
    virtual std::tuple<bool,cap_t,cost_t> get_mincost_edge(size_t from,size_t to)=0;
    virtual std::vector<std::tuple<long long, long long, size_t> > get_next(size_t)=0;
    virtual size_t size()=0;
};
class ref_flow:flow{
    typedef long long cap_t;
    typedef long long cost_t;
private:
    std::vector<std::map<std::tuple<size_t,cost_t>,cap_t>> _flow;
public:
    ref_flow(size_t N){
        _flow.resize(N);
    }
    cap_t get_capacity(size_t from,size_t to,cost_t cost)override{
        return _flow[from][std::make_tuple(to,cost)];
    }
    void add_vertex(size_t from,size_t to,cap_t cap,cost_t cost) override{
        if(from<0||to<0||from>=_flow.size()||to>=_flow.size()){
            abort();
        }
        if(cap<=0)return;
        auto& s=_flow[from];
        auto idx=std::make_tuple(to,cost);
        if(s.count(idx)){
            s[idx]+=cap;
        }else{
            s[idx]=cap;
        }
    }
    void del_vertex(size_t from,size_t to,cap_t cap,cost_t cost) override{
        if(from<0||to<0||from>=_flow.size()||to>=_flow.size()){
            abort();
        }
        if(cap<=0)return;
        auto& s=_flow[from];
        auto idx=std::make_tuple(to,cost);
        if(s.count(idx)){
            if(s[idx]<=cap){
                s.erase(idx);
            }else{
                s[idx]-=cap;
            }
        }
    }
    std::tuple<bool,cap_t,cost_t> get_mincost_edge(size_t from,size_t to) override{
        auto& s=_flow[from];
        auto itr=s.lower_bound(std::make_tuple(to,LLONG_MIN));
        auto [ito,icost]=itr->first;
        if(ito==to){
            return std::make_tuple(true,itr->second,icost);
        }else{
            return std::make_tuple(false,-1,-1);
        }
    }
    std::vector<std::tuple<cost_t, cap_t, size_t> > get_next(size_t from) override{
        std::vector<std::tuple<long long, long long, size_t> > ret;
        for (auto &&i : _flow[from])
        {
            auto [to,cost]=i.first;
            auto cap = i.second;
            ret.push_back(std::make_tuple(cost,cap,to));
        }
        return ret;
    }
    size_t size()override{
        return _flow.size();
    }
};

std::tuple<bool,long long> minCostFlow(ref_flow& f,size_t s,size_t t,long long cap){
    typedef long long ll;
    using namespace std;
    typedef tuple<ll,ll,size_t,size_t> cost_cap_from_cur_t;
    vector<ll> potential(f.size());
    ll INF=LLONG_MAX;
    ll ret = 0;
    ll curcap=0;
    while(curcap<cap){
        priority_queue<cost_cap_from_cur_t,vector<cost_cap_from_cur_t>,greater<cost_cap_from_cur_t>> q;
        vector<tuple<ll,ll,size_t>> cost_cap_from(f.size(),make_tuple(INF,0,f.size()+1));
        auto s_to = f.get_next(s);
        q.push(make_tuple(0,INF,f.size(),s));
        cost_cap_from[s]=make_tuple(0,INF,f.size());
        while(!q.empty()){
            auto [cost,cap,from,cur]=q.top();q.pop();
            auto v = f.get_next(cur);
            for (auto &&i : v)
            {
                auto [ncost,ncap,to]=i;
                auto [tcost,tcap,tfrom]=cost_cap_from[to];
                ll newcost=cost+(ncost+potential[cur]-potential[to]);
                if(newcost<tcost){
                    cost_cap_from[to]=make_tuple(newcost,min(cap,ncap),cur);
                    q.push(make_tuple(newcost,min(cap,ncap),cur,to));
                }
            }
        }
        for(size_t i=0;i<f.size();++i){
            potential[i]+=get<0>(cost_cap_from[i]);
        }
        auto [_,tcap,tfrom]=cost_cap_from[t];
        if(tfrom==f.size()+1||tcap<=0)break;
        if(curcap+tcap<=cap)
          curcap+=tcap;
        else{
          tcap=cap-curcap;
          curcap=cap;
        }
        ret+=(potential[t])*tcap;
        auto curidx=t;
        while(curidx!=s){
            auto [curcost,__,curfrom]=cost_cap_from[curidx];
            ll realcost=potential[curidx]-potential[curfrom];
            f.del_vertex(curfrom,curidx,tcap,realcost);
            f.add_vertex(curidx,curfrom,tcap,-realcost);
            curidx=curfrom;
        }
    }
    if(curcap<cap){
        return make_tuple(false,-1);
    }else{
        return make_tuple(true,ret);
    }
}
std::tuple<bool,long long> minCostFlowNeg(ref_flow& f,size_t s,size_t t,long long cap){
    typedef long long ll;
    using namespace std;
    typedef tuple<ll,ll,size_t,size_t> cost_cap_from_cur_t;
    vector<ll> potential(f.size());
    ll INF=LLONG_MAX>>3;
    ll ret = 0;
    ll curcap=0;
    bool clear_negcycle=false;
    while(curcap<cap){
        if(clear_negcycle){
            auto [flag,cost]=minCostFlow(f,s,t,cap-curcap);
            return make_tuple(flag,cost+ret);
        }
        vector<tuple<ll,ll,size_t>> cost_cap_from(f.size(),make_tuple(INF,0,f.size()+1));
        cost_cap_from[s]=make_tuple(0,INF,f.size()+0);
        auto s_to = f.get_next(s);
        for (size_t times = 0; times < f.size()-1; times++)
        {
            for (size_t i = 0; i < f.size(); i++)
            {
                for (auto &&j : f.get_next(i))
                {
                    auto [rcost,rcap,rto]=j;
                    ll pcost =rcost+potential[i]-potential[rto];
                    auto [tcost,tcap,tfrom]=cost_cap_from[rto];
                    auto [ccost,ccap,cfrom]=cost_cap_from[i];
                    if(tcost-pcost>ccost){
                        cost_cap_from[rto]=make_tuple(ccost+pcost,min(ccap,rcap),i);
                    }
                }
                
            }
        }
        if(!clear_negcycle){
            ll has_negcycle=([&](){
                for (size_t i = 0; i < f.size(); i++)
                {
                    for (auto &&j : f.get_next(i))
                    {
                        auto [ncost,ncap,nto]=j;
                        ll pcost = ncost+potential[i]-potential[nto];
                        auto [tcost,tcap,tfrom]=cost_cap_from[nto];
                        auto [ccost,ccap,cfrom]=cost_cap_from[i];
                        if(tcost-pcost>ccost){
                            ll cur=i;
                            for (size_t times = 0; times < f.size()-1; times++)
                            {
                                cur=get<2>(cost_cap_from[ret]);
                            }
                            return cur;
                        }
                    }
                }
                return -1LL;
                })();            
            if(has_negcycle!=-1){
                ll sumcost=0;
                size_t start = (size_t)has_negcycle;
                size_t cur=start;
                size_t prev=get<2>(cost_cap_from[start]);
                ll maxcap=INF;
                vector<tuple<size_t,size_t,ll>> edges;
                do{
                    auto [tcost,tcap,tfrom]=cost_cap_from[cur];
                    auto [ccost,ccap,cfrom]=cost_cap_from[prev];
                    auto [flag,ecap,ecost]=f.get_mincost_edge(prev,cur);
                    maxcap=max(maxcap,ecap);
                    sumcost+=ecost;
                    edges.push_back(make_tuple(prev,cur,ecost));
                    cur=prev;
                    prev=get<2>(cost_cap_from[prev]);
                }while(cur!=start);
                ret+=maxcap*sumcost;
                for (auto &&e : edges)
                {
                    auto [from,to,cost]=e;
                    f.del_vertex(from,to,maxcap,cost);
                    f.add_vertex(to,from,maxcap,-cost);
                }
                continue;
            }else{
                clear_negcycle=true;
            }
        }
        for(size_t i=0;i<f.size();++i){
            potential[i]+=get<0>(cost_cap_from[i]);
        }
        auto [_,tcap,tfrom]=cost_cap_from[t];
        if(tfrom==f.size()+1||tcap<=0)break;
        if(curcap+tcap<=cap)
          curcap+=tcap;
        else{
          tcap=cap-curcap;
          curcap=cap;
        }
        ret+=(potential[t])*tcap;
        auto curidx=t;
        while(curidx!=s){
            auto [curcost,__,curfrom]=cost_cap_from[curidx];
            ll realcost=potential[curidx]-potential[curfrom];
            f.del_vertex(curfrom,curidx,tcap,realcost);
            f.add_vertex(curidx,curfrom,tcap,-realcost);
            curidx=curfrom;
        }
    }
    if(curcap<cap){
        return make_tuple(false,-1);
    }else{
        return make_tuple(true,ret);
    }
}