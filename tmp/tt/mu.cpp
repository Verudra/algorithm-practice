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
int mu(int x){
    int res = -1;
    for(int i = 2;i*i <= x;i ++){
        if(x%i == 0){
            res = -res;
            x /= i;
            if(x%i == 0) return 0;
        }
    }
    if(x > 1) res = -res;
    return res;
}
vi get_mu(int n){
    vector<bool>vis(n+1);
    vi prims,mu(n+1);
    for(int i = 2;i <= n;i ++){
        if(!vis[i]){
            prims.push_back(i);
            mu[i] = -1;
        }
        for(auto t : prims){
            if(t*i > n) break;
            vis[t*i] = true;
            if(i%t != 0){
                mu[i*t] = -mu[i];
            }
            else{
                mu[i*t] = 0;
                break;
            }
        }
    }
    return mu;
}
void work(){
    
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