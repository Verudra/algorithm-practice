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
    int n,d; cin >> n >> d;
    vi a(n+1);
    For(i,1,n) cin >> a[i];
    deque<pii>mx,mi;
    int L = 1;
    int len = 0;
    For(i,1,n){
        while(!mx.empty() && mx.back().second<=a[i]) mx.pop_back();
        while(!mi.empty() && mi.back().second>=a[i]) mi.pop_back();
        mx.push_back({i,a[i]}); mi.push_back({i,a[i]});
        while(mx.front().second-mi.front().second>d){
            if(mx.front().first<mi.front().first){
                L = mx.front().first+1;
                mx.pop_front();
            }
            else{
                L = mi.front().first+1;
                mi.pop_front();
            }
        }
        len = max(i-L+1,len);
    }
    cout << len;
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