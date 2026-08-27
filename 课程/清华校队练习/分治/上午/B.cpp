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
void usort(int l,int r){
    if(l == r) return ;
    int mid = l+r>>1;
    usort(l,mid); usort(mid+1,r);
    int tsa[N], cnt1 = 0;
    int tl = l,tr = mid+1;
    while(tl <= mid && tr <= r){
        if(sa[tl] <= sa[tr]) tsa[++cnt1] = sa[tl++];
        else tsa[++cnt1] = sa[tr++];
    }
    while(tl <= mid) tsa[++cnt1] = sa[tl++];
    while(tr <= r) tsa[++cnt1] = sa[tr++];
    For(i,l,r) sa[i] = tsa[i-l+1];
    return ;
}
void work(){
    int n; cin >> n;
    For(i,1,n) cin >> sa[i];
    usort(1,n);
    For(i,1,n) cout << sa[i] << ' ';
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