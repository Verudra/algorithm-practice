#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int M = 2700005;
int ch[M][26],rh[M],qh[M],tot;
struct Group{
    int lrt,rrt;
    bool use;
};
struct Rule{
    int y,nxt;
};
struct Ask{
    int y,id,nxt;
};
vector<Group>g(1);
vector<Rule> rule(1);
vector<Ask> ask(1);
vi ans,cnt;
unordered_map<string,int> mp;

int addl(int rt,string s,int l){
    int u = rt;
    Rof(i,0,l-1){
        int c = s[i]-'a';
        if(!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];
    }
    return u;
}
int addr(int rt,string s,int r){
    int u = rt;
    For(i,r+1,s.size()-1){
        int c = s[i]-'a';
        if(!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];
    }
    return u;
}
int findl(int rt,string s,int l){
    int u=rt;
    Rof(i,0,l-1){
        int c = s[i]-'a';
        if(!ch[u][c]) break;
        u = ch[u][c];
    }
    return u;
}
string getkey(string a,string b,int l,int r){
    int len = r-l+1;
    return a.substr(l,len) + '{' + b.substr(l,len);
}
void dfs(int u){
    for(int e = rh[u];e;e=rule[e].nxt) cnt[rule[e].y] ++;
    for(int e = qh[u];e;e=ask[e].nxt) ans[ask[e].id] += cnt[ask[e].y];
    for(int c = 0;c < 26;c ++){
        if(ch[u][c]) dfs(ch[u][c]);
    }
    for(int e = rh[u];e;e=rule[e].nxt) cnt[rule[e].y] --;
}
void work(){
    int n,q; cin >> n >> q;
    For(i,1,n){
        string a,b; cin >> a >> b;
        if(a == b) continue;
        int l = 0, r = a.size()-1;
        while(a[l] == b[l]) l ++;
        while(a[r] == b[r]) r --;
        string key = getkey(a,b,l,r);
        int id;
        auto it = mp.find(key);
        if(it == mp.end()){
            id = (int)g.size();
            mp[key] = id;
            g.push_back({++tot,++tot,false}); // false 是什么?
        }
        else id = it->second; // 这个auto返回了什么?
        int x = addl(g[id].lrt,a,l);
        int y = addr(g[id].rrt,a,r);
        rule.push_back({y,rh[x]});
        rh[x] = (int)rule.size()-1;
    }
    ans.assign(q+1,0);
    For(i,1,q){
        string a,b; cin >> a >> b;
        if(a.size() != b.size()) continue;
        int l = 0,r = (int)a.size()-1;
        while(a[l] == b[l]) l ++;
        while(a[r] == b[r]) r --;
        auto it = mp.find(getkey(a,b,l,r));
        if(it == mp.end()) continue;
        int k = it->second;
        g[k].use = true;
        int x = findl(g[k].lrt,a,l);
        int y = g[k].rrt;
        ask.push_back({y,i,qh[x]});
        qh[x] = (int) ask.size()-1;
        For(j,r+1,a.size()-1){
            int c = a[j]-'a';
            if(!ch[y][c]) break;
            y = ch[y][c];
            ask.push_back({y,i,qh[x]});
            qh[x] = (int)ask.size()-1;
        }

    }
    cnt.assign(tot+1,0);
    For(k,1,g.size()-1){
        if(g[k].use) dfs(g[k].lrt);
    }
    For(i,1,q) cout << ans[i] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}