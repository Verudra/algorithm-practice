#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int mp[N][N], ps[N][N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> mp[i][j];
            mp[i][j] = (mp[i][j]==0?1:0);
            mp[i][j] += mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
        }
    }
    int ans = 0;
    for(int lx = 1;lx <= n;lx ++){
        for(int ly = 1;ly <= m;ly ++){
            for(int rx = lx;rx <= n;rx ++){
                for(int ry = ly;ry <= m;ry ++){
                    auto get0 = [&](int lx,int ly,int rx,int ry){
                        return mp[rx][ry]-mp[lx-1][ry]-mp[rx][ly-1]+mp[lx-1][ly-1];
                    };
                    if(get0(lx,ly,rx,ry)==0) ans = max(ans,(ry-ly+1)*(rx-lx+1));
                }
            }
        }
    }
    cout << ans;
    return 0;
}