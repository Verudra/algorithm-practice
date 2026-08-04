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
void work(){
    int n; cin >> n;
    vvi v(n+1,vi(n+1,0)), dp(n+1,vi(n+1,-INF)),path(n+1,vi(n+1,0));
    For(i,1,n) For(j,1,i) cin >> v[i][j];
    dp[1][1] = v[1][1];
    For(i,2,n) For(j,1,i){
        if(dp[i-1][j] > dp[i-1][j-1]){
            dp[i][j] = dp[i-1][j];
            path[i][j] = 1;
        }
        else{
            dp[i][j] = dp[i-1][j-1];
            path[i][j] = 2;
        }
        dp[i][j] += v[i][j];
    }
    stack<int>stk;
    int mx = 0;
    For(i,1,n) if(dp[n][mx] < dp[n][i]) mx = i;
    cout << dp[n][mx] << '\n';
    Rof(i,1,n){
        stk.push(mx);
        if(path[i][mx] == 2) mx --;
    }
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }
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