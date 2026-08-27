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
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    pque<int,vector<int>,greater<int> > pq;
    int q,v; cin >> q >> v;
    while(q --){
        int op; cin >> op;
        if(op == 1){
            int t,w; cin >> t >> w;
            pq.push(t-w);
        }
        else{
            int t; cin >> t;
            if(pq.empty()){
                cout << "-1\n";
                continue;
            }
            int now = pq.top(); pq.pop();
            cout << min(t-now,v) << '\n';
        }
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