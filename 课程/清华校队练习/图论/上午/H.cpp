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
const int N = 2e5;
bool vis[N];
queue<pii> q;
void fun(int pos,int tim){
    if(pos < 0 || pos >= N || vis[pos]) return ;
    vis[pos] = true;
    q.push({pos,tim});
    return ;
}
void work(){
    int n,k; cin >> n >> k;
    q.push({n,0});
    while(!q.empty()){
        auto [pos,tim] = q.front(); q.pop();
        vis[pos] = true;
        if(pos == k){
            cout << tim;
            return ;
        }
        fun(pos+1,tim+1);
        fun(pos-1,tim+1);
        fun(pos*2,tim+1);
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