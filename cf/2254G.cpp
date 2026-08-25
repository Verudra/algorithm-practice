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
void work(){
    int n; cin >> n;
    vi a(n+1), p(n+1);
    For(i,1,n) cin >> a[i];
    For(i,2,n) cin >> p[i];
    priority_queue<int,vi,greater<int>> pq[n+1];
    vi bk;
    Rof(i,1,n){
        if(pq[i].empty()){
            pq[i].push(a[i]);
        }
        else{
            int t = pq[i].top();
            pq[i].pop();
            pq[i].push(max(t,a[i]));
            bk.push_back(min(t,a[i]));
        }
        if(i != 1){
            int fa = p[i];
            if(pq[i].size() > pq[fa].size()) swap(pq[i],pq[fa]);
            while(!pq[i].empty()){
                pq[fa].push(pq[i].top());
                pq[i].pop();
            }
        }
    }
    int cntl = pq[1].size();
    vi ans(n+1,-1);
    ans[cntl] = 0;
    while(!pq[1].empty()){
        ans[cntl] += pq[1].top();
        pq[1].pop();
    }
    sort(bk.rbegin(),bk.rend());
    rep(i,n-cntl){
        ans[i+cntl+1] = ans[i+cntl] + bk[i];
    }
    For(i,1,n) cout << ans[i] << ' ';
    cout << '\n';
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