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
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
int ans;
int fun2(int n,int x,int k){
    int t = n/4;
    if(t <= k){
        ans += x*(t*3+n%4);
        return k-t;
    }else{
        ans += x*(n-k*4+k*3);
        return 0;
    }
}
int fun1(int n,int x,int k){
    int t = n/3;
    if(t <= k){
        ans += x*(t*2+n%3);
        return k-t;
    }else{
        ans += x*(n-k*3+k*2);
        return 0;
    }
}
void work(){
    ans = 0;
    int n,m,x,y,k; cin >> n >> m >> x >> y >> k;
    if(x > y){
        k=fun1(n,x,k);
        fun2(m,y,k);
    }else{
        k=fun2(m,y,k);
        fun1(n,x,k);
    }
    cout << ans << '\n';
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