#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
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
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,m; cin >> n >> m;
    vvi v(n+1,vi(m+1)),ans(n*m+1,vi(4));
    int cnt = 0;
    For(i,1,n){
        For(j,1,m){
            int t; cin >> t;
            if(t != 0){
                cnt ++;
                ans[cnt][0] = i;
                ans[cnt][1] = j;
                ans[cnt][2] = t;
            }
        }
    }
    For(i,1,cnt) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}