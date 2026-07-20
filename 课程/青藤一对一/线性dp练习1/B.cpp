#include<iostream>
#include<vector>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l ,r) for(int i = (l); i <= (r); i++)
#define Rof(i, l ,r) for(int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n; cin >> n;
    vector<int> v(n+1);
    v[0] = 1, v[1] = 1;
    For(i, 2, n){
        v[i] = v[i-1] + v[i-2];
        v[i] %= mod;
    }
    cout << v[n];
    return ;
}
signed main(){
    int T=1; 
    while(T --) work();
    return 0;
}