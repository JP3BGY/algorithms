#include<vector>
#include<complex>
#include<cmath>
template <typename F>
void fft(std::vector<std::complex<F>> &a,bool is_invert=false){
    if(a.size()==1)return;
    using namespace std;
    vector<complex<F>> diva,divb;
    for (size_t i = 0; i < a.size()/2; i++)
    {
        diva.push_back(a[2*i]);
        divb.push_back(a[2*i+1]);
    }
    fft(diva,is_invert);fft(divb,is_invert);
    F inv = (is_invert?-1:1);
    complex<F> cur=1,zeta=polar<F>(1,inv*2*M_PIf64/a.size());
    size_t sz=a.size();
    for (size_t i = 0; i < a.size(); i++)
    {
        a[i]=diva[i%(sz/2)]+cur*divb[i%(sz/2)];
        cur*=zeta;
    }
}

template<typename T1,typename T2>
std::vector<T2> multiply(std::vector<T1> f,std::vector<T1> g){
    using namespace std;
    size_t sz=1;
    while(sz<f.size()+g.size())sz<<=1;
    vector<complex<T2>> cf(sz),cg(sz);
    for (size_t i = 0; i < f.size(); i++)
    {
        cf[i]=static_cast<complex<T2>>(f[i]);
    }
    for (size_t i = 0; i < g.size(); i++)
    {
        cg[i]=static_cast<complex<T2>>(g[i]);
    }
    fft(cf);
    fft(cg);
    for (size_t i = 0; i < sz; i++)
    {
        cf[i]*=cg[i];
    }
    fft(cf,true);
    vector<T2> ret;
    for (size_t i = 0; i < sz; i++)
    {
        ret.push_back(cf[i].real()/sz);
    }
    return ret;
}