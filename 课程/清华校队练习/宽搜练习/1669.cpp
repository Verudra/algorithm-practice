#include<bits/stdc++.h>
using namespace std;
const int N = 400;
bool vis[N][N], visf[N][N];
int tx[] = {-1,1,0,0};
int ty[] = {0,0,-1,1};
map<pair<int,int>,bool>mp;
struct node{
    int x,y,t;
};
bool ck(int x,int y){
    if(x >= 0 && x <= 300 && y >= 0 && y <= 300) return true;
    return false;
}
int main(){
    int m;
    vector<node>v;
    cin >> m;
    for(int i = 1;i <= m;i ++){
        node t;
        cin >> t.x >> t.y >> t.t;
        for(int j = 0;j < 4;j ++){
            int nx = t.x+tx[j];
            int ny = t.y+ty[j];
            mp[{nx,ny}] = true;
        }
        mp[{t.x,t.y}] = true;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),[](const node& a,const node& b){
        return a.t < b.t;
    });
    queue<node>q; int p=0;
    q.push({0,0,0});
    int T = 0;
    while(!q.empty()){
        queue<node>tq;
        T ++;
        auto fall = [](node& u){
            for(int i = 0;i < 4;i ++){
                int nx = u.x+tx[i];
                int ny = u.y+ty[i];
                if(ck(nx,ny)) visf[nx][ny] = true;
            }
            visf[u.x][u.y] = true;
        };
        while(p < v.size() && v[p].t <= T) fall(v[p ++]);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            // printf("x:%d y:%d t:%d\n",u.x,u.y,u.t);
            // if(visf[u.x][u.y]) continue;
            if(!mp[{u.x,u.y}]){
                cout << u.t << '\n';
                return 0;
            }
            for(int i = 0;i < 4;i ++){
                int nx = u.x+tx[i];
                int ny = u.y+ty[i];
                if(ck(nx,ny)&&!vis[nx][ny]&&!visf[nx][ny]){
                    vis[nx][ny] = true;
                    tq.push({nx,ny,u.t+1});
                }
            }
        }
        q = tq;
    }
    cout << "-1";
    return 0;
}