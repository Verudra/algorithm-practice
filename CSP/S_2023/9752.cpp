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
bool pd(int x,vi& v){
    int now = 5;
    vector<pair<int,int>> res;
    while(now){
        int t = x%10; x /= 10;
        if(t != v[now]) res.push_back({now,(t-v[now]+10)%10});
        now --;
    }
    if(res.size() == 1 || (res.size() == 2 && abs(res[0].first-res[1].first) == 1 && res[0].second == res[1].second)) return true;
    return false;
}
void work(){
    int n; cin >> n;
    vvi vs(n+1,vi(6));
    For(i,1,n){
        For(j,1,5) cin >> vs[i][j];
    }
    int cnt = 0;
    For(i,0,99999){
        bool f = false;
        For(j,1,n) if(!pd(i,vs[j])) f = true;
        if(!f) cnt ++;
    }
    cout << cnt;
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