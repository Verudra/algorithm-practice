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
    vvi v1(n+1,vi(m+1)), v2(n+1,vi(m+1));
    For(i,1,n){
        For(j,1,m) cin >> v1[i][j];
    }
    For(i,1,n){
        For(j,1,m) cin >> v2[i][j];
    }
    For(i,1,n){
        For(j,1,m) cout << v1[i][j] + v2[i][j] << ' ';
        cout << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}