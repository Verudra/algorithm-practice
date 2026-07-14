#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char mp[N][N];
bool vis[N][N];
int tx[] = {-1,1,0,0};
int ty[] = {0,0,-1,1};
struct node{
    int x,y,cnt;
};
int main(){
    int n,m;
    while(cin >> n >> m){
        memset(vis,0,sizeof(vis));
        if(n == m && m == 0) break;
        int bx,by;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                cin >> mp[i][j];
                if(mp[i][j] == '@') bx = i,by = j;
            }
        }
        queue<node>q;
        q.push({bx,by,0});
        vis[bx][by] = true;
        bool flag = false;
        while(!q.empty()){
            // cout << "!";
            auto [x,y,cnt] = q.front();
            // cout << x << ' ' << y << ' ' << cnt << '\n';
            // system("pause");
            q.pop();
            if(mp[x][y]=='*'){
                cout << cnt << '\n';
                flag = true;
                break;
            }
            for(int i = 0;i < 4;i ++){
                int nx = x+tx[i];
                int ny = y+ty[i];
                auto ck = [&](int x,int y){
                    if(x >= 1 && x <= n && y >= 1 && y <= m && (mp[x][y] == '.' || mp[x][y] == '*') && !vis[x][y]) return true;
                    return false;
                };
                if(ck(nx,ny)){
                    vis[nx][ny] = true;
                    q.push({nx,ny,cnt+1});
                }
            }
        }
        if(!flag) cout << "-1\n";
    }
    return 0;
}