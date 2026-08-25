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
    int n,m; cin >> n >> m;
    vi v; For(i,1,n*m){
        int t; cin >> t; v.push_back(t);
    }
    int fi = v[0];
    sort(v.begin(),v.end(),[](int a,int b){return a > b;});
    for(int i = 0;i < n*m;i ++){
        if(v[i] == fi){
            int y = i/n+1;
            int x = i%n+1;
            cout << y << ' ';
            if(y&1) cout << x;
            else cout << n-x+1;
            return ;
        }
    }
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