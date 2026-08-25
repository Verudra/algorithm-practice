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
const int mod = 998244353;
const int N = 1e6+10;
int jc[N];
void init(){
    jc[0] = 1;
    For(i,1,N-1) jc[i] = (jc[i-1]*i)%mod;
    return ;
}
int ksm(int x,int p){
    int res = 1;
    while(p){
        if(p&1) res = res*x%mod;
        x = x*x%mod;
        p >>= 1;
    }
    return res;
}
int inv(int x){
    return ksm(x,mod-2);
}
int C(int n,int m){
    if(n == -1 && m == -1) return 1;
    if(n < 0 || m < 0 || m > n) return 0;
    return jc[n]*inv(jc[n-m]*jc[m]%mod)%mod;
}
void work(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0, cntl0 = 0, cntl1 = 0;
    rep(i,s.size()){
        if(i != 0 && s[i] != s[i-1]){
            if(s[i-1] == '0') cntl0 ++;
            else cntl1 ++;
        }
        if(s[i] == '0') cnt0 ++;
        else cnt1 ++;
    }
    if(s.back() == '0') cntl0 ++;
    else cntl1 ++;
    cout << C(cnt0-1,cntl0-1)*C(cnt1-1,cntl1-1)%mod << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}