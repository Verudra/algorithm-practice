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
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
int cacl(int x){
    return x*(x+1)/2;
}
vi tri3(int x){
    int m = 0;
    while(cacl(m+1) <= x) m ++;
    vi v(x+1,-1);
    For(i,0,m) v[cacl(i)] = i;
    For(i,0,m){
        For(j,i,m){
            int r = x-cacl(i)-cacl(j);
            if(r<0) break;
            if(v[r] != -1) return {i,j,v[r]};
        }
    }
    return {};
}
void work(){
    int k; cin >> k;
    if(k <= 3){
        string ans = "a" + string(k,'b');
        cout << ans.size() << ' ' << '2' << '\n';
        cout << ans << '\n';
        return ;
    }
    k -= 3;
    int t1 = 1;
    while(cacl(t1+1) <= k) t1 ++;
    k -= cacl(t1);
    vi v = tri3(k);
    string ans = "a"+string(t1,'a');
    For(i,0,2) ans += 'b'+string(v[i],'a');
    cout << ans.size() << ' ' << '2' << '\n';
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