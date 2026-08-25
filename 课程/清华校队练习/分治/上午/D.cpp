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
const int N = 1005;
int sa[N];
int maxsum(int l,int r){
    if(l == r) return sa[l];
    int mid = l+r>>1;
    int lmx = maxsum(l,mid), rmx = maxsum(mid+1,r);
    int Lsufmx = -INF, Rpremx = -INF;
    int t = 0;
    Rof(i,l,mid){
        t += sa[i];
        Lsufmx = max(t,Lsufmx);
    }
    t = 0;
    For(i,mid+1,r){
        t += sa[i];
        Rpremx = max(Rpremx,t);
    }
    return max({lmx,rmx,Lsufmx+Rpremx});
}
void work(){
    int n; cin >> n;
    For(i,1,n) cin >> sa[i];
    cout << maxsum(1,n);
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