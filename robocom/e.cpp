#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 305;
int dp[N][N][2];
int dpt[N][N];
struct node{
    int t,p,c;
}sa[N];
const int inf = 0x7f7f7f7f7f7f7f7f;
signed main(){
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i = 1;i <= n;i ++){
        scanf("%lld%lld%lld",&sa[i].t,&sa[i].p,&sa[i].c);
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= k;j ++){
            if(i == 1){
                dp[i][j][0] = sa[i].p*sa[i].t;
                dp[i][j][1] = 0;
                dpt[i][j] = sa[i].t;
                continue;
            }
            if(j == 0){
                dp[i][j][0] = dp[i-1][j][0] + sa[i].p*sa[i].t;
                dp[i][j][1] = 0;
                dpt[i][j] = sa[i].t;
                continue;
            }
            if(dp[i-1][j][0]+sa[i].p*sa[i].t < dp[i-1][j-1][0]+dpt[i-1][j-1]*sa[i].p){
                dp[i][j][0] = dp[i-1][j][0]+sa[i].p*sa[i].t;
                dp[i][j][1] = dp[i-1][j][1];
                dpt[i][j] = sa[i].t;
            }
            else if(dp[i-1][j][0]+sa[i].p*sa[i].t > dp[i-1][j-1][0]+dpt[i-1][j-1]*sa[i].p){
                dp[i][j][0] = dp[i-1][j-1][0]+dpt[i-1][j-1]*sa[i].p;
                dp[i][j][1] = dp[i-1][j-1][1]+sa[i].c;
                dpt[i][j] = dpt[i-1][j-1];
            }
            else{
                dp[i][j][0] = dp[i-1][j-1][0]+sa[i-1].t*sa[i].p;
                // dp[i][j][1] = min(dp[i-1][j][1],dp[i-1][j-1][1]+sa[i].c);
                if(dp[i-1][j][1] < dp[i-1][j-1][1]+sa[i].c){
                    dp[i][j][1] = dp[i-1][j][1];
                    dpt[i][j] = dpt[i-1][j];
                }
                else{
                    dp[i][j][1] = dp[i-1][j-1][1]+sa[i].c;
                    dpt[i][j] = dpt[i-1][j-1];
                }
            }
        }
    }
    int ans1=inf,ans2=0;
    for(int i = 0;i <= k;i ++){
        if(ans1 > dp[n][i][0]){
            ans1 = dp[n][i][0];
            ans2 = dp[n][i][1];
        }
        else if(ans1 == dp[n][i][0]){
            ans2 = min(ans2,dp[n][i][1]);
        }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}