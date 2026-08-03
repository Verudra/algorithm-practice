#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
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
struct node{
    int id,tim;
    bool operator< (const node& b)const{
        if(tim != b.tim) return tim > b.tim;
        return id > b.id;
    }
};
void work(){
    int n,m; cin >> n >> m;
    priority_queue<int,vector<int>,greater<int>>pqf;
    priority_queue<node>pqw;
    For(i,1,m) pqf.push(i);
    For(i,1,n){
        int a,s; cin >> a >> s;
        while(!pqw.empty() && pqw.top().tim <= a){
            pqf.push(pqw.top().id); pqw.pop();
        }
        if(pqf.size()){
            int t = pqf.top(); pqf.pop();
            pqw.push({t,a+s});
            cout << t << ' ' << a+s << '\n';
        }
        else{
            node t = pqw.top(); pqw.pop();
            pqw.push({t.id,t.tim+s});
            cout << t.id << ' ' << t.tim+s << '\n';
        }
    }
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