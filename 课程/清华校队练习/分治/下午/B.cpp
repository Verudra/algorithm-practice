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
const int N = 1<<11;
int mp[N][N];
void fun(int x,int y,int k){
    if(k == 0){
        mp[x][y] = 1;
        return ;
    }
    int len = 1<<k-1;
    fun(x+len,y,k-1);
    fun(x,y+len,k-1);
    fun(x+len,y+len,k-1);
    return ;
}
void work(){
    int n;cin >> n;
    fun(1,1,n);
    For(i,1,1<<n){
        For(j,1,1<<n) cout << mp[i][j] << ' ';
        cout << '\n';
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