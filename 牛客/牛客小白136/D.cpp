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
    int n,m,k; cin >> n >> m >> k;
    int L = -1e10, R = 1e10;
    auto gs2 = [](int x){
        return x*(2*x+1)*(x+1)/6;
    };
    auto calc = [&](int x)->pair<int,int> {
        int res = 0, cnt = 0;
        For(i,1,n){
            int L = 0, R = m;
            while(L < R){
                int mid = L+R+1>>1;
                if(i*i-mid*mid < x) R = mid-1;
                else L = mid;
            }
            res += L*i*i-gs2(L);
            cnt += L;
        }
        return {res,cnt};
    };
    while(L < R){
        int mid = L+R>>1;
        auto res = calc(mid);
        if(res.second >= k) L = mid;
        else R = mid-1;
    }
    auto res = calc(L);
    if(res.second > k) res.first -= (res.second-k)*L;
    cout << res.first << '\n';
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