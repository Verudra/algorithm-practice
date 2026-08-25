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
int n = 0;
void work(){
    int ans = 0,cnt = 0;
    if(n == 1){
        cout << 2 << '\n';
        return ;
    }
    for(int i = 2;i*i <= n;i ++){
        if(n%i == 0){
            int res = 1;
            while(n%i == 0){
                res *= i;
                n /= i;
            }
            ans += res;
            cnt ++;
        }
    }
    if(n > 1) ans += n,cnt ++;
    if(cnt == 1) ans += 1;
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(cin >> n){if(n == 0) break; work();}
    return 0;
}