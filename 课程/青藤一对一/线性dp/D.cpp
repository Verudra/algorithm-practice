#include <bits/stdc++.h>
using namespace std;
const int N = 25;
bool vis[N][N];
int tx[] = {-2,-2,-1,1,2,2,1,-1,0};
int ty[] = {-1,1,2,2,1,-1,-2,-2,0};
long long dp[N][N];
int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    auto ck = [&](int x,int y){
        return (x>=0&&x<=n&&y>=0&&y<=m);
    };
    for(int i = 0;i < 9;i ++){
        int px = x+tx[i];
        int py = y+ty[i];
        if(ck(px,py)) vis[px][py] = true;
    }
    dp[0][0] = 1;
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            if(vis[i][j]) continue;
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[n][m];
    return 0;
}