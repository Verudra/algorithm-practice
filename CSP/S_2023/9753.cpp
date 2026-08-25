#include<bits/stdc++.h>
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
const int N = 2e6+10;
int last[N][27], dp[N];
int state[N];
void work(){
    int n; string s; cin >> n >> s;
    s = ' ' + s;
    // dp[0] = 1;
    int ans = 0;
    For(i,1,n){
        int ltstat = state[i-1];
        int c = s[i]-'a';
        int pos = last[ltstat][c];
        if(pos == 0){
            state[i] = i;
        }else{
            state[i] = state[pos-1];
            dp[i] = dp[pos-1]+1;
        }
        last[state[i]][c] = i;
        ans += dp[i];
    }
    cout << ans << '\n';
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