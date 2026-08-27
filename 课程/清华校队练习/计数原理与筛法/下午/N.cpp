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
const int N = 2e5+10;
int fun(int x){
    int res = 1;
    for(int i = 2;i*i <= x;i ++){
        if(x%i == 0){
            int cnt = 0;
            while(x%i == 0){
                cnt ++;
                x /= i;
            }
            res *= cnt+1;
        }
    }
    if(x > 1) res *= 2;
    return res;
}
void work(){
    int n; cin >> n;
    int mx,mxcnt = -1;
    for(int i = 1;i <= n;i ++){
        int res = fun(i);
        if(res > mxcnt){
            mx = i;
            mxcnt = res;
        }
    }
    cout << mx << ' ' << mxcnt;
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