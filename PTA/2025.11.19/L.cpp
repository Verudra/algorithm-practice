#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>vec;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vec.resize(n+1);
    vector<int>sv(101);
    for(int i = 1;i <= n;i ++){
        int k; scanf("%d",&k);
        vec[i].resize(k+1);
        for(int j = 1;j <= k;j ++){
            int t; scanf("%d",&t);
            vec[i][j] = t;
        }
    }
    int pos = 1;
    for(int i = 1;i <= m;i ++){
        int opt; scanf("%d",&opt);
        if(opt == 0){
            int j; scanf("%d",&j);
            pos = vec[pos][j];
        }
        else if(opt == 1){
            int j; scanf("%d",&j);
            sv[j] = pos;
            printf("%d\n",pos);
        }
        else if(opt == 2){
            int j; scanf("%d",&j);
            pos = sv[j];
        }
    }
    printf("%d",pos);
    return 0;
}