#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char mp[N][N];
bool vis[N][N];
struct node{
    int x,y;
};
int px[8] = {-1,-1,-1,0,0,1,1,1};
int py[8] = {-1,0,1,-1,1,-1,0,1};
int n,m;
void bfs(int x,int y){
    queue<node>q;
    q.push({x,y});
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0;i < 8;i ++){
            int tx = now.x+px[i];
            int ty = now.y+py[i];
            auto pd = [=](int x,int y)->bool {
                if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
                return false;
            };
            if(pd(tx,ty)&&!vis[tx][ty]&&mp[tx][ty]=='W'){
                q.push({tx,ty});
                vis[tx][ty] = true;
            }
        }
    }
    return ;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> mp[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(vis[i][j] == false && mp[i][j] == 'W'){
                bfs(i,j);
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}