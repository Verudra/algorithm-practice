#include<bits/stdc++.h>
using namespace std;
const int M = 205;
const int N = 35;
struct node{
    int w,c,p;
}sa[N];
int dp[M];
int main(){
    int m,n;
    cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        auto& t = sa[i];
        cin >> t.w >> t.c >> t.p;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = m;j >= 0;j --){
            int up = sa[i].p;
            if(sa[i].p == 0) up = M;
            for(int k = 1;k <= up;k ++){
                if(j-k*sa[i].w < 0) break;
                dp[j] = max(dp[j],dp[j-k*sa[i].w]+sa[i].c*k);
            }
        }
    }
    cout << dp[m];
    return 0;
}