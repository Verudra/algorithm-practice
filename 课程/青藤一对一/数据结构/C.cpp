#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5+10;
int sa[N][24];
int gcd(int x, int y){
    return y==0?x:gcd(y,x%y);
}
void work(){
    int n,q; cin >> n >> q;
    For(i,1,n) cin >> sa[i][0];
    For(k,1,23){
        For(i,1,n-(1<<k)+1){
            sa[i][k] = gcd(sa[i][k-1], sa[i+(1<<k-1)][k-1]);
        }
    }
    while(q --){
        int l,r; cin >> l >> r;
        int c = log2(r-l+1);
        cout << gcd(sa[l][c],sa[r-(1<<c)+1][c]) << '\n';
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