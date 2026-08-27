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
const int N = 1005;
int sa[N],ps[N];
int n,c; 
int ans = 0;
void dfs(int l,int now){
    if(now > c) return ;
    if(now+ps[n]-ps[l-1] <= ans) return ;
    ans = max(ans,now);
    For(i,l,n) dfs(i+1,now+sa[i]);
    return ;
}
void work(){
    cin >> n >> c;
    For(i,1,n) cin >> sa[i];
    sort(sa+1,sa+1+n,[](int a,int b){return a > b;});
    For(i,1,n) ps[i] = ps[i-1]+sa[i];
    dfs(1,0);
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