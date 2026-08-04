#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,k,m,q; cin >> n >> k >> m >> q;
    string las;int lacnt=0; 
    map<string,int>strcnt;
    map<string,int>firpos;
    map<string,bool>pd;
    vi ans;
    For(i,1,n){
        string ts; cin >> ts;
        strcnt[ts] ++;
        if(firpos.count(ts) == 0) firpos[ts] = i;
        if(pd[ts] && i-firpos[ts]>m && strcnt[ts] <= q) ans.push_back(i);
        if(ts != las){
            las = ts; lacnt = 1;
        }
        else{
            lacnt ++;
            if(lacnt >= k) pd[ts] = true;
        }
    }
    if(ans.size()) for(auto i : ans) cout << i << ' ';
    else cout << "empty";
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}
/*
1
10 2 3 4
a
a
a
b
a
b
b
c
b
a
*/