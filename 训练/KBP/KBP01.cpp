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
    int w,t;
    bool operator<(const node b)const{
        return w*b.t > t*b.w;
    }
};
void print(__int128 x){
    if(x < 0){
        putchar('-');
        print(-x);
    }
    if(x < 10){
        putchar(x+'0');
        return ;
    }
    print(x/10);
    putchar(x%10+'0');
    return ;
}
void work(){
    int n; cin >> n;
    vector<node>v;
    For(i,1,n){
        int t,w; cin >> t >> w;
        v.push_back({w,t});
    }
    sort(v.begin(),v.end());
    __int128 T = 0;
    __int128 ans = 0;
    for(auto [w,t] : v){
        T += t;
        ans += w*T;
    }
    print(ans);
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