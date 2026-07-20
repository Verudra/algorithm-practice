#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int memo[35][35];
int n,m; 
int dfs(int u,int k){
    if(k == 0){
        if(u == 1) return 1;
        else return 0;
    }
    if(memo[u][k]!=-1) return memo[u][k];
    int left = (u==1?n:u-1), right = (u==n?1:u+1);
    return memo[u][k] = dfs(left,k-1) + dfs(right,k-1);
}
void work(){
    cin >> n >> m;
    memset(memo,-1,sizeof memo);
    cout << dfs(1,m);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}