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
#define len(s) ((int)s.size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int DAYS[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<int>prims;
const int N = 10010;
bool vis[N];
void work(){
    int T; cin >> T;
    vector<string>v;
    For(i,2,N){
        if(!vis[i]){
            prims.push_back(i);
            for(int j = i*i;j < N;j += i) vis[j] = true;
        }
    }
    auto pdrn = [](int x){
        return (x%4==0&&x%100!=0 || x%400==0);
    };
    auto pdzs = [](int x){
        if(x==1) return false;
        for(int i = 2;i*i <= x;i ++){
            if(x%i==0) return false;
        }
        return true;
    };
    auto pd = [&](int a,int b,int c){
        return pdzs(a)&&pdzs(b)&&pdzs(c);
    };
    for(auto y:prims){
        if(y > 9999) break;
        int _ = pdrn(y);
        string ys = to_string(y);
        ys = string(4-len(ys),'0')+ys;
        for(auto m:prims){
            if(m > 12) break;
            string ms = to_string(m);
            ms = string(2-len(ms),'0')+ms;
            for(auto d:prims){
                if(d > (m==2?DAYS[m]+_:DAYS[m])) break;
                string ds = to_string(d);
                ds = string(2-len(ds),'0')+ds;
                if(pd(d,m*100+d,y*10000+m*100+d)) v.push_back(ys+ms+ds);
            }
        }
    }
    while(T --){
        string s; cin >> s;
        int ans = 0;
        for(auto ts : v){
            bool flag = false;
            For(i,0,len(s)-1){
                if(s[i]!='-' && s[i]!=ts[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag) ans ++;
        }
        cout << ans << '\n';
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