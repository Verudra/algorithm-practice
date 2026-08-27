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
const int N = 1e7+10;
bool vis[N];
vi prims;
bool pd(int x){
    while(x){
        if(x%10 == 7) return true;
        x /= 10;
    }
    return false;
}
void init(int n){
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            if(pd(i)){
                for(int j = i;j <= n;j += i){
                    vis[j] = true;
                }
            }
        }
        if(!vis[i]) prims.push_back(i);
    }
    return ;
}
void work(){
    int n; cin >> n;
    if(vis[n]){
        cout << -1 << '\n';
        return ;
    }
    cout << prims[lower_bound(prims.begin(),prims.end(),n)-prims.begin()+1] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e7);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}