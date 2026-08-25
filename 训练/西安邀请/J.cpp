#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n; cin >> n;
    vi v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    int l = -1,r = -1;
    rep(i,n-2){
        int val = v[i]+v[i+1];
        int p = lower_bound(v.begin(),v.end(),val)-v.begin();
        p --;
        // if(p == v.size()) p --;
        if(p-i+1 > r-l+1) l=i,r=p;
    }
    if(r-l+1 < 3) cout << 0;
    else{cout << r-l+1 << ' '; For(i,l,r) cout << v[i] << ' ';}
    cout << '\n';
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
