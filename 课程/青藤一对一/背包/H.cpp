#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = 32005;
struct node{
    int v, p, q;
}sa[N];
int dp[M];
struct node1{
    int w,v;
};
int main(){
    int m,n;
    cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        node& t = sa[i];
        cin >> t.v >> t.p >> t.q;
    }
    for(int i = 1;i <= n;i ++){
        if(sa[i].q != 0) continue;
        vector<node>v1;
        for(int j = 1;j <= n;j ++){
            if(sa[j].q == i) v1.push_back(sa[j]);
        }
        auto fun = [&](node u,vector<node>&v)->vector<node1> {
            vector<node1>res;
            for(int i = 0;i < (1<<v.size());i ++){
                node1 t;t.w = u.v; t.v = u.p*u.v;
                for(int j = 0;j < v.size();j ++){
                    if((1<<j)&i){
                        t.w += v[j].v;
                        t.v += v[j].p*v[j].v;
                    }
                }
                res.push_back(t);
            }
            return res;
        };
        vector<node1>res = fun(sa[i],v1);
        for(int j = m;j >= 0;j --){
            for(auto k : res){
                if(j-k.w >= 0) dp[j] = max(dp[j],dp[j-k.w]+k.v);
            }
        }
    }
    cout << dp[m];
    return 0;
}