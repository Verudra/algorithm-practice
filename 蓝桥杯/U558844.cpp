#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void work(){
    int n;
    scanf("%d",&n);
    vector<int>v(n+1);
    for(int i = 1;i <= n;i ++) scanf("%d",&v[i]);
    bool flag = false;
    if(v[n] != 1) flag = true;
    for(int i = 2;i <= n;i ++){
        if(v[i] > v[i-1]) flag = true;
    }
    if(flag){
        printf("0\n");
        return ;
    }
    long long ans = 1;
    for(int i = 2;i <= n;i ++){
        if(v[i] == v[i-1]){
            long long tmp = n-v[i]-i+2;
            if(tmp <= 0){
                ans = 0;break;
            }
            ans = ans*tmp%MOD;
        }
    }
    printf("%lld\n",ans);
    return ;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}