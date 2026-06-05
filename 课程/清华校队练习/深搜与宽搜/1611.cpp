#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n,cnt;
const int N = 32;
bool vis[N];
vector<ll>v;
void dfs(int u,ll now){
    if(u > cnt){
        if(now) v.push_back(now);
        return ;
    }
    dfs(u+1,now+pow(k,u));
    dfs(u+1,now);
}
int main(){
    cin >> k >> n; int n1 = n;
    while(n){cnt ++;n>>=1;}
    dfs(0,0);
    sort(v.begin(),v.end());
    cout << v[n1-1];
    return 0;
}