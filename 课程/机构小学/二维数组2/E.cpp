#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
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
    int n; cin >> n;
    vvi v(n+1,vi(n+1));
    int cnt = 1, x = 1, y = 0;
    while(cnt <= n*n){
        while(y+1 <= n && v[x][y+1] == 0) v[x][++y] = cnt++;
        while(x+1 <= n && v[x+1][y] == 0) v[++x][y] = cnt++;
        while(y-1 >= 1 && v[x][y-1] == 0) v[x][--y] = cnt++;
        while(x-1 >= 1 && v[x-1][y] == 0) v[--x][y] = cnt++;
    }
    For(i,1,n){
        For(j,1,n) cout << left << setw(4) << v[i][j];
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