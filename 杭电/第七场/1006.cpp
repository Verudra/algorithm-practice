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
    int n,m; cin >> n >> m;
    vi rp(n+1,-INF), lp(n+1,n+1), rc(n+1,-INF);
    int minr = INF;
    rep(i,m){
        int a,b; cin >> a >> b;
        if(a > b) swap(a,b);
        rc[a] = a;
        rp[a] = max(rp[a],b);
        lp[a] = min(lp[a],b-1);
        minr = min(minr,b);
    }
    For(i,2,n) rp[i] = max(rp[i],rp[i-1]);
    Rof(i,1,n-1) lp[i] = min(lp[i],lp[i+1]);
    Rof(i,1,n-1) rc[i] = max(rc[i],rc[i+1]);
    For(l,2,n-1){
        if(l > minr) break;
        int low = max({l,rc[l],rp[l-1]}), high = min(lp[l],n-1);
        if(low <= high){
            cout << "Yes\n";
            cout << l << ' ' << high+1 << '\n';
            return ;
        }
    }
    cout << "No\n";
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