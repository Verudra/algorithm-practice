#include <bits/stdc++.h>
using namespace std;
int k,x;
bool flag = false;
void dfs(int u){
    if(u >= 1e5) return ;
    if(u == x){
        flag = true;
        return ;
    }
    dfs(u*2+1); dfs(u*3+1);
    return ;
}
int main(){
    scanf("%d,%d",&k,&x);
    dfs(k);
    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}