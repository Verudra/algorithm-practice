#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char ans[N];
int n;
void dfs(int u,int cntl,int cntr){
    if(u > 2*n){
        for(int i = 1;i <= n*2;i ++) cout << ans[i];
        cout << '\n';
        return ;
    }
    if(cntl < n){
        ans[u] = '(';
        dfs(u+1,cntl+1,cntr);
    }
    if(cntl > cntr){
        ans[u] = ')';
        dfs(u+1,cntl,cntr+1);
    }
    return ;
}
int main(){
    cin >> n;
    dfs(1,0,0);
    return 0;
}