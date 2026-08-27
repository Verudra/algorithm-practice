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
void work(){
    int T; cin >> T;
    auto pd1 = [](int x){
        for(int i = 2;i*i <= x;i ++){
            if(x%i==0) return false;
        }
        return true;
    };
    auto pd = [&](int a,int b,int c){
        if(pd1(a) && pd1(b) && pd1(c)) return true;
        return false;
    };
    auto pdrn = [](int y){
        if(y%4==0&&y%100!=0 || y%400==0) return 1;
        return 0;
    };
    while(T --){
        string s; cin >> s;
        int ans = 0;
        For(y,1,9999){
            int _ = pdrn(y);
            For(m,1,12){
                For(d,1,m==2?DAYS[m]+_:DAYS[m]){
                    string ys = to_string(y);
                    ys = string(4-len(ys),'0')+ys;
                    string ms = to_string(m);
                    ms = string(2-len(ms),'0')+ms;
                    string ds = to_string(d);
                    ds = string(2-len(ds),'0')+ds;
                    string date = ys+ms+ds;
                    bool flag = false;
                    For(i,0,len(date)-1){
                        if(s[i] != '-' && date[i] != s[i]){
                            flag = true;
                            break;
                        }
                    }
                    if(flag) continue;
                    if(pd(d,m*100+d,y*10000+m*100+d)) ans ++;
                }
            }
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