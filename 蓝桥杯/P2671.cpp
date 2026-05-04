#include <bits/stdc++.h>
using namespace std;
const long long MOD = 10007;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>num(n),col(n);
    for(int i = 0;i < n;i ++) scanf("%d",&num[i]);
    for(int i = 0;i < n;i ++) scanf("%d",&col[i]);
    vector<vector<long long> > cnt(m,vector<long long>(2,0)),sum(m,vector<long long>(2,0));
    long long ans = 0;
    for(int i = 0;i < n;i ++){
        int op = i%2;
        cnt[col[i]-1][op] ++;
        sum[col[i]-1][op] += num[i];
        
    }
    for(int i = 0;i < n;i ++){
        int op = i%2;
        ans = ans + (cnt[col[i]-1][op]-2)*(i+1)%MOD*num[i]%MOD + (i+1)*sum[col[i]-1][op]%MOD;
        ans %= MOD;
    }
    printf("%lld",ans);
    return 0;
}