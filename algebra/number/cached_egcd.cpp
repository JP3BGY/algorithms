#define MOD 1000000007
#define MAX 20000005
long long cache_f[MAX],cache_invf[MAX];
void init_cache_egcd(){
    long long maxn=MAX;
    cache_f[0]=1; for (long long i=1;i<maxn;i++) cache_f[i]=cache_f[i-1]*i%MOD;
    cache_invf[0]=cache_invf[1]=1; for (long long i=2;i<maxn;i++) cache_invf[i]=MOD-(MOD/i)*cache_invf[MOD%i]%MOD;
    for (long long i=2;i<maxn;i++) cache_invf[i]=cache_invf[i-1]*cache_invf[i]%MOD;
}

long long C(long long x,long long y){
    if (y<0||y>x) return 0;
    return cache_f[x]*cache_invf[y]%MOD*cache_invf[x-y]%MOD;
}