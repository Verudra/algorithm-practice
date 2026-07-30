#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include<queue>
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
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
struct node{
    int pos,val;
    bool operator< (const node& t)const{
        return val < t.val;
    }
};
void work(){
    int n; cin >> n;
    vi v(n+2,0);
    For(i,1,n) cin >> v[i];
    priority_queue<node>pq;
    auto get2m = [&](int pos){
        return max(v[pos-1],v[pos+1]);
    };
    auto getval = [&](int pos){
        // if(pos == 1 && pos == n) return 0;
        bool fl = true, fr = true;
        if(v[pos-1] == 0) fl = false;
        if(v[pos+1] == 0) fr = false;
        int res = 0;
        if(fl) res += max(0ll, v[pos]-v[pos-2]);
        if(fr) res += max(0ll, v[pos]-v[pos+2]);
        return res-get2m(pos);
    };
    For(i,1,n) pq.push({i,getval(i)});
    int ans = 0;
    auto push = [&](int pos){
        if(pos < 1 || pos > n) return ;
        if(v[pos] == 0) return ;
        pq.push({pos, getval(pos)});
        return ;
    };
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        if(v[t.pos] == 0 || t.val != getval(t.pos)) continue;
        ans += get2m(t.pos);
        v[t.pos] = 0;
        push(t.pos-2);
        push(t.pos+2);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}