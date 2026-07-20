#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 200005;
int tre[N];
int n,m; 
int lowbit(int x){
    return x&-x;
}
void add(int u,int v){
    while(u <= n) tre[u] += v,u+=lowbit(u);
}
int query(int u){
    int s = 0;
    while(u){
        s += tre[u];
        u -= lowbit(u);
    }
    return s;
}
int query(int l,int r){
    return query(r)-query(l-1);
}
void work(){
    cin >> n >> m;
    For(i,1,n){
        int t; cin >> t;
        add(i,t);
    }
    For(i,1,m){
        int op,a,b; cin >> op >> a >> b;
        if(op == 1) add(a,b);
        else cout << query(a,b) << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}