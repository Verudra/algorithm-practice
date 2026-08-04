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
const int N = 205;
int dp[N][N];
string s; 
map<char,char> mp;
void init(){
    mp['('] = ')';
    mp[')'] = '(';
    mp['['] = ']';
    mp[']'] = '[';
    return ;
}
bool pr(char l, char r){
    if(l=='(' || l=='[') if(mp[l] == r) return true;
    return false;
}
void dfs(int l,int r){
    if(l == r){
        char c = s[l];
        if(c=='('||c=='[') cout << c << mp[c];
        else cout << mp[c] << c;
        return ;
    }
    if(pr(s[l],s[r])&&dp[l][r]==dp[l+1][r-1]){
        cout << s[l]; dfs(l+1,r-1); cout << s[r];
    }
    else{
        For(k,l,r){
            if(dp[l][k]+dp[k+1][r]==dp[l][r]){
                dfs(l,k); dfs(k+1,r);
                break;
            }
        }
    }
    return ;
}
void work(){
    cin >> s;
    int n = s.length();
    s = " " + s;
    For(len, 1, n){
        For(l, 1, n-len+1){
            int r = l+len-1;
            if(len == 1) dp[l][r] = 1;
            else{
                if(pr(s[l],s[r])) dp[l][r] = dp[l+1][r-1];
                else dp[l][r] = INF;
            }
            For(k, l, r-1) dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
        }
    }
    cout << dp[1][n] << '\n';
    dfs(1,n);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}