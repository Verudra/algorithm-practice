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
    vector<char>v(n+1);
    For(i,1,n) cin >> v[i];
    auto fz = [](char c){
        if(c == '1') return '0';
        return '1';
    };
    auto pd = [](char a,char b){
        if(a == b || a == '?') return true;
        return false;
    };
    auto ck = [&](char a,char b){
        for(int i = 1;i <= n;i += 2,a=fz(a),b=fz(b)){
            if(!pd(v[i],a) || (i+1<=n && !pd(v[i+1],b))) return false;
        }
        return true;
    };
    int ans = 0;
    if(ck('0','0')) ans ++;
    if(ck('0','1')) ans ++;
    if(ck('1','0')) ans ++;
    if(ck('1','1')) ans ++;
    cout << ans << '\n';
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