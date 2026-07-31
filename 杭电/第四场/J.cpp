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
const int mod = 998244353;
int ksm(int a,int p){
    int res = 1;
    while(p){
        if(p&1) res = res*a%mod;
        a = a*a%mod;
        p >>= 1;
    }
    return res;
}
void work(){
    int n; cin >> n;
    vi v(n+1);
    For(i,1,n) cin >> v[i];
    unordered_map<int,int>mp;
    int cnt = 0;
    int cnt1 = 0; // 可插可不插
    vi vk;
    bool flag = false;
    For(i,1,n){
        if(mp[v[i]] == 4){
            if(cnt){
                flag = true;
                break;
            }
            vk.push_back(cnt1-1);
            cnt1 = 0;
            mp.clear();
        }
        if(mp[v[i]] == 0) cnt ++;
        if(mp[v[i]] == 3){
            cnt --;
            if(cnt == 0) cnt1 ++;
        }
        mp[v[i]] ++;
    }
    // cout << '!' << '\n';
    if(flag || cnt){
        cout << 0 << '\n';
        return ;
    }
    if(cnt1 > 0) vk.push_back(cnt1-1);
    int ans = 1;
    // cout << "!";
    for(auto k : vk){
        // cout << k << ' ';
        ans = ans*ksm(2,k)%mod;
    }
    // cout << "!";
    cout << ans << '\n';
    return ;
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout <<  "!" << ksm(2,2) << '\n';
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}