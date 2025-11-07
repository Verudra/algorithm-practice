#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int sa[N][N];
bool visR[N],visC[N],visD[N<<2],visF[N<<2];
int getD(int x,int y){
    return 8-y+x;
}
int getF(int x,int y){
    return y+x-1;
}
int dfs(int n,int val){
    if(n == 9) return val;
    int res = -1;
    for(int i = 1;i <= 8;i ++){
        if(visC[i] || visD[getD(n,i)] || visF[getF(n,i)]) continue;
        visC[i] = true; visD[getD(n,i)] = true; visF[getF(n,i)] = true;
        res = max(res,dfs(n+1,val+sa[n][i]));
        visC[i] = false; visD[getD(n,i)] = false; visF[getF(n,i)] = false;
    }
    return res;
}
void work(){
    for(int i = 1;i <= 8;i ++){
        for(int j = 1;j <= 8;j ++){
            scanf("%d",&sa[i][j]);
        }
    }
    printf("%d\n",dfs(1,0));
    return ;
}
int main(){
    int k;
    scanf("%d",&k);
    while(k --){
        work();
    }
    return 0;
}
/*
2
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
*/