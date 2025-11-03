#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
void work(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n+2);
    int maxn = -INF;
    vec[0] = vec[n+1] = INF;
    for(int i = 1;i <= n;i ++) scanf("%d",&vec[i]),maxn = max(maxn,vec[i]),vec[i] = (i&1)==0?maxn:vec[i];
    long long ans = 0;
    for(int i = 1;i <= n;i ++){
        if(i&1) ans += max(vec[i]-min(vec[i-1],vec[i+1])+1,0);
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}