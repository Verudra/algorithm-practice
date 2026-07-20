#include<iostream>
#include<vector>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n, m; cin >> n >> m;
    vector<vector<char> >v(n+1,vector<char>(m+1));
    For(i ,1 ,n){
        For(j, 1, m){
            cin >> v[i][j];
        }
    }
    vector<vector<int> >dp(n+1, vector<int>(m+1));
    For(i, 1, m){
        if(v[1][i] == '#') break;
        dp[1][i] = 1;
    }
    For(i, 1, n){
        if(v[i][1] == '#') break;
        dp[i][1] = 1;
    }
    For(i, 2, n){
        For(j, 2, m){
            if(v[i][j] == '#') continue;
            else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout << dp[n][m];
    return ;
}
signed main(){
    int T=1; 
    while(T --) work();
    return 0;
}