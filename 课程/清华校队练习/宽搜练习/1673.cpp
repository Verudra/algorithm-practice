#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
const int N = 105;
char c[N][N];
bool vis[N][N];
int tx[] = {-1,-1,-1,0,0,1,1,1};
int ty[] = {-1,0,1,-1,1,-1,0,1};
struct node{
    int x,y;
};
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> c[i][j];
        }
    }
    cin >> x >> y;
    queue<node>q;
    q.push({x,y});
    vis[x][y] = true;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        c[x][y] = '2';
        auto ck = [&](int x,int y){
            if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
            return false;
        };
        for(int i = 0;i < 8;i ++){
            int nx = x+tx[i];
            int ny = y+ty[i];
            if(ck(nx,ny)){
                if(c[nx][ny] == '1' && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
                c[nx][ny] = '2';
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cout << c[i][j];
        }
        cout << '\n';
    }
    return 0;
}