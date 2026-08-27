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
    int w,z,q; cin >> w >> z >> q;
    auto init = [&](int n){
        vector<bool>vis(n+1);
        vi res(n+1);
        auto pd = [&](int x){
            int res = 0;
            while(x){
                if(x%10 == z) res ++;
                x /= 10;
            }
            return res==0?0:1;
        };
        For(i,2,n-1){
            if(!vis[i]){
                res[i] += w;
                int t = pd(i);
                for(int j = i;j < n;j += i){
                    vis[j] = true;
                    res[j] += t;
                }
            }
        }
        For(i,2,n-1){
            if(res[i] >= w) res[i] = 1;
            else res[i] = 0;
            res[i] += res[i-1];
        }
        return res;
    };
    vi ans = init(5e6+10);
    while(q --){
        int L,R; cin >> L >> R;
        cout << ans[R]-ans[L-1] << '\n';
    }
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