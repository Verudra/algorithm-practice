#include<bits/stdc++.h>
using namespace std;
int n,r;
const int N = 23;
int ans[N];
void dfs(int u,int l){
    if(u > r){
        for(int i = 1;i <= r;i ++){
            printf("%3d",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = l;i <= n;i ++){
        ans[u] = i;
        dfs(u+1,i+1);
    }
    return ;
}
int main(){
    cin >> n >> r;
    dfs(1,1);
    return 0;
}