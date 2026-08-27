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
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    vector<string>s,t;
    int n,m; cin >> n >> m;
    For(i,1,n){
        string ts; cin >> ts; s.push_back(ts);
    }
    For(i,1,m){
        string tt; cin >> tt; t.push_back(tt);
    }
    int ans = 0;
    rep(i,n){
        bool f = 0;
        rep(j,n){
            if(j == i) continue;
            if(s[i] == s[j]){
                f = true;
                break;
            }
        }
        rep(j,m){
            if(s[i].find(t[j]) != string::npos){
                f = true;
                break;
            }
        }
        if(f) ans ++;
    }
    cout << ans;
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