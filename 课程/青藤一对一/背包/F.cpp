#include <bits/stdc++.h>
using namespace std;
const int N = 35;
const int M = 205;
struct node{
    int w,c,t;
    bool operator< (const node b)const{
        return t < b.t;
    }
}sa[N];
// int W[N], C[N], T[N];
int dp[M];
int main(){
    int m,n,t;
    cin >> m >> n >> t;
    for(int i = 1;i <= n;i ++){
        auto& t = sa[i];
        cin >> t.w >> t.c >> t.t;
    }
    for(int i = 1;i <= t;i ++){
        for(int j = m;j >= 0;j --){
            int maxn = dp[j];
            for(int k = 1;k <= n;k ++){
                if(sa[k].t == i && j-sa[k].w >= 0){
                    maxn = max(maxn, dp[j-sa[k].w]+sa[k].c);
                }
            }
            dp[j] = maxn;
        }
    }
    cout << dp[m];
    return 0;
}