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
struct node{
    int a,d;
};
struct node1{
    int id,cnt,val;
    bool operator< (const node1 b)const{
        return val < b.val;
    }
};
void work(){
    int n,k; cin >> n >> k;
    vector<node>v(n+1); 
    priority_queue<node1>pq;
    For(i,1,n){
        node& t = v[i];
        cin >> t.a >> t.d;
        pq.push({i,0,t.a});
    }
    int ans = 0;
    while(k --){
        auto t = pq.top(); pq.pop();
        ans += t.val;
        pq.push({t.id, t.cnt+1, v[t.id].a-v[t.id].d*(t.cnt+1)});
    }
    cout << ans;
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