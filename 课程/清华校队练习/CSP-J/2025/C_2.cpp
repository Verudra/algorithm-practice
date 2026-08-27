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
const int N = 500005;
int sa[N];
void work(){
    int n,k; cin >> n >> k;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    for(int i = 2;i <= n;i ++) sa[i] ^= sa[i-1];
    int R = -1, ans = 0;
    map<int,int> mp;
    mp[0] = 0;
    For(i,1,n){
        if(mp.count(sa[i]^k) && mp[sa[i]^k] >= R){
            ans ++;
            R = i;
        }
        mp[sa[i]] = i;
    }
    cout << ans;
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