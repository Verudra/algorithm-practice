#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
map<int,string>mp2;
int cnt;
const int N = 1e5+10;
int fa[N];
int gfa(int u){
    if(u == fa[u]) return u;
    return fa[u] = gfa(fa[u]);
}
void uni(int u,int v){
    fa[gfa(v)] = gfa(u);
}
int main(){
    char c;string s;
    for(int i = 1;i < N;i ++) fa[i] = i;
    string lfa;
    while(1){
        cin >> c; if(c == '$') return 0;
        cin >> s; if(!mp.count(s)) mp[s] = ++cnt, mp2[cnt] = s;
        if(c == '#') lfa = s;
        else if(c == '+') uni(mp[lfa],mp[s]);
        else cout << s << ' ' << mp2[gfa(mp[s])] << '\n';
    }
    return 0;
}