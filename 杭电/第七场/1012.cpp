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
vector<vector<int> > v;
vi siz,ht;
int ans2 = 0;
void dfs(int u){
    priority_queue<int,vi,greater<int> > pq1,pq2;
    for(auto to : v[u]){
        dfs(to);
        siz[u] += siz[to];
        pq1.push(ht[to]);
        pq2.push(siz[to]);
    }
    while(pq1.size() > 2){
        int t1 = pq1.top(); pq1.pop();
        int t2 = pq1.top(); pq1.pop();
        pq1.push(max(t1,t2)+1);
    }
    int ans1 = -1;
    while(pq2.size() > 2){
        int t1 = pq2.top(); pq2.pop();
        int t2 = pq2.top(); pq2.pop();
        pq2.push(t1+t2);
        ans2 += t1+t2;
    }
    while(!pq1.empty()){
        int t = pq1.top(); pq1.pop();
        ans1 = max(ans1, t);
    }
    ht[u] = ans1+1;
    while(!pq2.empty()){
        int t = pq2.top(); pq2.pop();
        ans2 += t;
    }
    return ;
}
void work(){
    int n; cin >> n;
    ans2 = 0;
    v.assign(n+1,vi());
    siz.assign(n+1,1);
    ht.assign(n+1,0);
    for(int i = 2;i <= n;i ++){
        int t; cin >> t;
        v[t].push_back(i);
    }
    dfs(1);
    cout << ht[1] << ' ' << ans2 << '\n';
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