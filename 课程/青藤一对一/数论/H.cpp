#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int INF = 0x7f7f7f7f;
int sa[N];
map<int,int>fac;
int main(){
    int n,m1,m2; cin >> n >> m1 >> m2;
    for(int i = 2;i*i <= m1;i ++){
        while(m1%i == 0){
            fac[i] ++;
            m1 /= i;
        }
    }
    if(m1 > 1) fac[m1] ++;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    int minn = INF;
    auto fun = [&](map<int,int>mp){
        int res = 0;
        for(auto [a,b]:fac){
            if(mp[a] == 0) return -1;
            else res = max(res, (b*m2+mp[a]-1)/mp[a]);
        }  
        return res;
    };
    for(int i = 1;i <= n;i ++){
        map<int,int>mp;
        for(int j = 2;j*j <= sa[i];j ++){
            while(sa[i]%j == 0){
                mp[j] ++;
                sa[i] /= j;
            }
        }
        if(sa[i] > 1) mp[sa[i]] ++;
        int res = fun(mp);
        if(res == -1) continue;
        else minn = min(minn,res);
    }
    cout << (minn==INF?-1:minn);
    return 0;
}