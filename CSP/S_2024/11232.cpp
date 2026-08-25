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
    int n,m,L,V; cin >> n >> m >> L >> V;
    struct node{
        int L,R;
    };
    struct node1{
        int d,v,a;
    };
    vector<node1> sa1;
    For(i,1,n){
        node1 t;
        cin >> t.d >> t.v >> t.a;
        sa1.push_back(t);
    }
    vi p;
    For(i,1,m){
        int t; cin >> t;
        p.push_back(t);
    }
    sort(p.begin(),p.end());
    vector<node>vec;
    auto f = [](int v,int a,int d,int x){
        return v*v+2*a*(x-d);
    };
    int ans1 = 0;
    For(i,1,n){
        auto [d,v,a] = sa1[i-1];
        int al = 0;
        int tl = 0, tr = m-1;
        while(tl < tr){
            int mid = tl+tr>>1;
            if(p[mid] < d) tl = mid+1;
            else tr = mid;
        }
        if(p[tl] < d) continue;
        al = tl;
        if(a >= 0){
            if(f(v,a,d,p.back()) <= V*V) continue;
            ans1 ++;
            int tl = al, tr = m-1;
            while(tl < tr){
                int mid = tl+tr>>1;
                if(f(v,a,d,p[mid]) <= V*V) tl = mid+1;
                else tr = mid;
            }
            vec.push_back({tl,m-1});
        }
        else{
            if(f(v,a,d,p[al]) <= V*V) continue;
            ans1 ++;
            int tl = al, tr = m-1;
            while(tl < tr){
                int mid = tl+tr+1>>1;
                if(f(v,a,d,p[mid]) > V*V) tl = mid;
                else tr = mid-1;
            }
            vec.push_back({al,tl});
        }
    }
    int lat = -1, ans2 = 0;
    sort(vec.begin(),vec.end(),[](node a,node b){
        return a.R < b.R;
    });
    for(auto [l,r] : vec){
        if(l > lat){
            ans2 ++;
            lat = r;
        }
    }
    cout << ans1 << ' ' << m-ans2 << '\n';
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