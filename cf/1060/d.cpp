#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct Edge{
    int nxt;
    int to;
}edg[N<<1];
int head[N],tot,d[N];
bool dep[N];
void add(int u,int v){
    ++tot;
    edg[tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
    d[v] ++;
}
void dfs(int u,int fa,bool f){
    dep[u] = f;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        if(to == fa) continue;
        dfs(to,u,!f);
    }
}
void work(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) head[i] = d[i] = dep[i] = 0;
    tot = 0;
    for(int i = 1;i < n;i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,-1,false);
    queue<int>q1,q2;
    for(int i = 1;i <= n;i ++){
        if(d[i] == 1 && i != n){
            if(dep[i] == false) q1.push(i);
            else q2.push(i);
        }
    }
    int cnt = n;
    bool now = true;
    vector<pair<int,int>> ops;
    while(cnt > 1){
        if(now){
            if(q2.empty()){
                ops.push_back(make_pair(1,-1));
                now = false;
            }
            else{
                ops.push_back(make_pair(2,q2.front()));
                for(int e = head[q2.front()];e;e = edg[e].nxt){
                    int to = edg[e].to;
                    d[to] --;
                    if(d[to] == 1 && to != n){
                        if(dep[to]) q2.push(to);
                        else q1.push(to);
                    }
                }
                q2.pop();
                ops.push_back(make_pair(1,-1));
                now = false;
                cnt --;
            }
        }
        else{
            if(q1.empty()){
                ops.push_back(make_pair(1,-1));
                now = true;
            }
            else{
                ops.push_back(make_pair(2,q1.front()));
                for(int e = head[q1.front()];e;e = edg[e].nxt){
                    int to = edg[e].to;
                    d[to] --;
                    if(d[to] == 1 && to != n){
                        if(dep[to]) q2.push(to);
                        else q1.push(to);
                    }
                }
                q1.pop();
                ops.push_back(make_pair(1,-1));
                now = true;
                cnt --;
            }
        }
    }
    printf("%d\n",(int)ops.size());
    for(auto i : ops){
        if(i.first == 1) printf("1\n");
        else printf("%d %d\n",i.first,i.second);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}