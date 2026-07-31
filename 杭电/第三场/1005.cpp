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
const int N = 1e6+10;
vi prim;
bool vis[N];
void init(){
    For(i,2,N-1){
        if(!vis[i]) prim.push_back(i);
        for(auto j : prim){
            if(j*i >= N) break;
            vis[j*i] = true;
            if(i%j == 0) break;
        }
    }
}
void work(){
    int x; cin >> x;
    int mx = -INF;
    for(auto i : prim){
        if(i*i*i > x) break;
        if(x%i == 0){
            int cnt = 0;
            while(x%i == 0){
                x /= i; cnt ++;
            }
            mx = max(mx,cnt);
        }
    }
    int t = sqrt(x); 
    // cout << "t:" << t << " sqrt:" << sqrt(t) << '\n';
    // cout << "!:" << sqrt(9) << '\n';
    // while((t+1)*(t+1) <= x) t ++;
    // while(t*t > x) t --;
    if(t*t == x) mx = max(mx, 2ll);
    else mx = max(mx, 1ll);
    // cout << mx << '\n';
    int ans = 0;
    while(mx){
        mx >>= 1;
        ans ++;
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}