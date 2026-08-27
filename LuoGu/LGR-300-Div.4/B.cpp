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
    int n,k; cin >> n >> k;
    int sum = 0;
    rep(i,n){
        int t; cin >> t;
        sum += t;
    }
    vi v;
    while(sum){
        v.push_back(sum%10); sum /= 10;
    }
    auto maxv = [](vi& v1, vi&v2){
        Rof(i,0,v1.size()-1) if(v1[i] != v2[i]) if(v1[i] > v2[i]) return v1; else return v2;
        return v1;
    };
    Rof(i,0,v.size()-1){
        vi mx = v;
        For(j,max(i-k+1,0ll),i-1){
            if(v[j] <= v[i]) continue;
            vi v1 = v;
            reverse(v1.begin()+j,v1.begin()+i+1);
            mx = maxv(mx,v1);
        }
        if(v != maxv(mx,v)){
            Rof(i,0,mx.size()-1) cout << mx[i];
            return ;
        }
    }
    Rof(i,0,v.size()-1) cout << v[i];
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