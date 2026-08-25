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
void work(){
    int n; cin >> n;
    vi v(n+1);
    For(i,1,n) cin >> v[i];
    vi ps(n+1);
    For(i,1,n) ps[i] = ps[i-1]+v[i];
    auto gs = [&](int l,int r){
        return ps[r] - ps[l-1];
    };
    int ax = -1, ay = -1;
    For(i,1,n){
        if(v[i] == 0) continue;
        int L = 1, R = i;
        while(L < R){
            int mid = L+R>>1;
            if(gs(mid,i) == v[i]) R = mid;
            else L = mid+1;
        }
        int l = L;
        L = i, R = n;
        while(L < R){
            int mid = L+R+1>>1;
            if(gs(i,mid) == v[i]) L = mid;
            else R = mid-1;
        }
        int r = L;
        if(ax == -1 && ay == -1){
            ax = v[i]; ay = r-l+1;
        }else{
            if(v[i]*ay < ax*(r-l+1)) ax = v[i], ay = r-l+1;
        }
    }
    int g = __gcd(ax,ay);
    cout << ax/g << ' ' << ay/g;
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
