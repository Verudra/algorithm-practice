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
bool vis[N];
vi prims;
void init(int n){
    For(i,2,n){
        if(!vis[i]){
            prims.push_back(i);
            for(int j = i*2;j <= n;j += i){
                vis[j] = true;
            }
        }
    }
    return ;
}
int up(int val){
    return upper_bound(prims.begin(),prims.end(),val)-prims.begin();
}
void work(){
    int n,q; cin >> n >> q;
    init(n);
    for(int i = 1;i <= q;i ++){
        int l,r; cin >> l >> r;
        cout << up(r)-up(l-1) << '\n';
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