#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int d[N+10];
const ll MOD = 1000000007;
ll inv[N+10];
ll fac[N+10];
ll ksm(ll a,ll p){
    ll res = 1;
    while(p){
        if(p&1) res = res*a%MOD;
        p >>= 1;
        a = a*a%MOD;
    }
    return res;
}
void init(){
    fac[0] = 1;
    for(int i = 1;i <= N;i ++) fac[i] = fac[i-1]*i%MOD;
    inv[0] = 1;
    inv[N] = ksm(fac[N],MOD-2);
    for(int i = N-1;i >= 1;i --) inv[i] = inv[i+1]*(i+1)%MOD;
    return ;
}
ll C(ll a,ll b){
    if(b < 0 || b > a) return 0;
    return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
int main(){
    init();
    int n;
    scanf("%d",&n);
    for(int i = 1;i < n;i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        d[u] ++; d[v] ++;
    }
    int l,r;
    scanf("%d%d",&l,&r);
    long long ans = 0;
    if(l <= 1 && 1 <= r) ans += n;
    if(l <= 2 && 2 <= r) ans += n-1;
    for(int i = 1;i <= n;i ++){
        int st = max(2,l-1), ed = min(d[i], r-1);
        for(int j = st;j <= ed;j ++){
            ans = ans+C(d[i],j);
            ans %= MOD;
        }
    }
    printf("%lld",ans%MOD);
    return 0;
}