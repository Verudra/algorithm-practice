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
struct node{
    int x,y;
};  
void work(){
    int n,m; cin >> n >> m;
    vector<int> v(n*m+1);
    unordered_map<int,int>mp;
    For(i,1,n) For(j,1,m) cin >> v[(i-1)*m+j];
    For(i,1,n) For(j,1,m){
        int t; cin >> t;
        mp[t] = (i-1)*m+j;
    }
    vi ans;
    For(i,1,n*m){
        int t = mp[v[i]];
        auto p = lower_bound(ans.begin(),ans.end(),t);
        if(p == ans.end()) ans.push_back(t);
        else *p = t;
    }
    cout << n*m-ans.size() << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}