#include<bits/stdc++.h>
using namespace std;
const int N = 1006;
char mp[N][N];
int cnt[N][N];
int tx[] = {-1,1,0,0};
int ty[] = {0,0,-1,1};
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> mp[i][j];
            if(mp[i][j]=='#'){
                for(int k = 0;k < 4;k ++){
                    int nx = i+tx[k];
                    int ny = j+ty[k];
                    cnt[nx][ny] ++;
                }
            }
        }
    }
    int tcnt = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(!cnt[i][j] && mp[i][j] == '.') tcnt ++;
        }
    }
    int ans = tcnt;
    auto ck = [&](int x,int y){
        if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
        return false;
    };
    // cout << "tcnt:" << tcnt << '\n';
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(mp[i][j] == '#'){
                int tans = tcnt;
                for(int k = 0;k < 4;k ++){
                    int nx = i+tx[k];
                    int ny = j+ty[k];
                    if(ck(nx,ny) && cnt[nx][ny]==1 && mp[nx][ny]=='.') tans ++;
                }
                if(cnt[i][j]==0) tans ++;
                ans = max(ans,tans);
            }
        }
    }
    cout << ans;
    return 0;
}