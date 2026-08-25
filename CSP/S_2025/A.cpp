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
void work(){
    int n; cin >> n;
    struct node{
        int a,b,c;
    };
    vector<node>v(n);
    int s(0);
    vector<node>v1,v2,v3;
    rep(i,n) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        int mx = max({v[i].a,v[i].b,v[i].c});
        if(v[i].a == mx) s += mx, v1.push_back(v[i]);
        else if(v[i].b == mx) s += mx, v2.push_back(v[i]);
        else s += mx, v3.push_back(v[i]);
    }
    auto fun = [=](vector<node>& v){
        auto gmid = [](const node& a){
            return a.a+a.b+a.c-max({a.a,a.b,a.c})-min({a.a,a.b,a.c});
        };
        auto gcz = [=](const node& a){
            return max({a.a,a.b,a.c})-gmid(a);
        };
        sort(v.begin(),v.end(),[=](const node& a, const node& b){
            return gcz(a) < gcz(b);
        }); 
        int res = 0; 
        rep(i,v.size()-n/2) res += gcz(v[i]);
        return res;
    };
    if(v1.size() > n/2) s -= fun(v1);
    if(v2.size() > n/2) s -= fun(v2);
    if(v3.size() > n/2) s -= fun(v3);
    cout << s << '\n';
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