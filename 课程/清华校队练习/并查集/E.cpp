#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int fa[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(u)] = gfa(v);
}
struct node{
    int x,y,t;  
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<node> v;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++){
        int x,y,t;
        cin >> x >> y >> t;
        v.push_back({x,y,t});
    }
    sort(v.begin(),v.end(),[](node a,node b){
        return a.t < b.t;
    });
    auto ck = [&](){
        for(int i = 2;i <= n;i ++){
            if(gfa(i) != gfa(i-1)) return false;
        }
        return true;
    };
    if(ck()){cout << 0; return 0;}
    for(auto i : v){
        uni(i.x,i.y);
        if(ck()){
            cout << i.t;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}