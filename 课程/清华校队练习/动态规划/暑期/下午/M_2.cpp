#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
int wts[] = {0,1,2,3,5,10,20};
void work(){
    vi sa;
    int sum = 0;
    For(i,1,6){
        int t; cin >> t;
        For(j,1,t) {sa.push_back(wts[i]);sum += wts[i];}
    }
    vi dp(sum+1);
    dp[0] = 1;
    for(auto w : sa){
        Rof(j,w,sum) dp[j] = max(dp[j],dp[j-w]);
    }
    int ans = 0;
    For(i,1,sum) if(dp[i]) ans ++;
    cout << "Total=" << ans;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}