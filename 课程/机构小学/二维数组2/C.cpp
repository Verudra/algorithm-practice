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
int tx[] = {-1,-1,-1,0,0,1,1,1}, ty[] = {-1,0,1,-1,1,-1,0,1};
void work(){
    int h,l,c,r;
    cin >> h >> l >> c >> r; c++,r++;
    vvi v(h+2,vi(l+2));
    For(i,1,h){
        For(j,1,l) cin >> v[i][j];
    }
    int ans = 0;
    For(i,0,7) ans += v[c+tx[i]][r+ty[i]];
    cout << ans;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}