#include<bits/stdc++.h>
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
    /*
        x%10
        
    */
    int a,b; cin >> a >> b;
    int c = a + b;
    int c1 = c;
    int d = 0;
    while(c > 0){
        int t = c%10;
        c = c/10;
        d = d*10 + t;
    }
    if(d == c1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    /*
        123 * 10 = 1230
        int t = 4; 1230 + t = 1234;
    */
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