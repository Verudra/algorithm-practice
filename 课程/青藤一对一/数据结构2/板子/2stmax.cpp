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
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 205;
const int K = 8;
short lg2[N];
void init_lg2(int n){
    lg2[0] = lg2[1] = 0;
    for(int i = 2;i <= n;i ++){
        lg2[i] = lg2[i/2]+1;
    }
    return ;
}
struct ST_max_2d{
    int st[K][K][N][N];
    void build(const vector<vector<int> >& v){
        int n = v.size();
        int m = v.front().size();
        init_lg2(max(n,m));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                st[0][0][i+1][j+1] = v[i][j];
            }
        }
        for(int ky = 1;ky < K && (1LL<<ky) <= m;ky ++){
            for(int x = 1;x <= n;x ++){
                for(int y = 1;y+(1LL<<ky)-1 <= m;y ++){
                    st[0][ky][x][y] = max(
                        st[0][ky-1][x][y],
                        st[0][ky-1][x][y+(1LL<<(ky-1))]
                    );
                }
            }
        }
        for(int kx = 1;kx < K && (1LL<<kx) <= n;kx ++){
            for(int ky = 0;ky < K && (1LL<<ky) <= m;ky ++){
                for(int x = 1;x+(1LL<<kx)-1 <= n;x ++){
                    for(int y = 1;y+(1LL<<ky)-1 <= m;y ++){
                        st[kx][ky][x][y] = max(
                            st[kx-1][ky][x][y],
                            st[kx-1][ky][x+(1LL<<(kx-1))][y]
                        );
                    }
                }
            }
        }
        return ;
    }
    int query(int lx,int ly,int rx,int ry){
        int cx = lg2[rx-lx+1],cy = lg2[ry-ly+1];
        return max({
            st[cx][cy][lx][ly],
            st[cx][cy][lx][ry-(1LL<<cy)+1],
            st[cx][cy][rx-(1LL<<cx)+1][ly],
            st[cx][cy][rx-(1LL<<cx)+1][ry-(1LL<<cy)+1]
        });
    }
};
ST_max_2d stmax2;

void work(){
    int n,m,q; cin >> n >> m >> q;
    vvi v(n,vi(m));
    rep(i,n) rep(j,m) cin >> v[i][j];
    stmax2.build(v);
    while(q --){
        int lx,ly,rx,ry; cin >> lx >> ly >> rx >> ry;
        cout << stmax2.query(lx,ly,rx,ry) << '\n';
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