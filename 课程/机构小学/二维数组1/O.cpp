#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int mp[N][N];
int main(){
    int n; cin >> n;
    int x = 1, y = 0, cnt = 1;
    while(cnt<=n*n){
        while(y+1 <= n && mp[x][y+1] == 0) mp[x][++y] = cnt++;
        while(x+1 <= n && mp[x+1][y] == 0) mp[++x][y] = cnt++;
        while(y-1 >= 1 && mp[x][y-1] == 0) mp[x][--y] = cnt++;
        while(x-1 >= 1 && mp[x-1][y] == 0) mp[--x][y] = cnt++;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            printf("%-4d",mp[i][j]);
        }
        cout << '\n';
    }
    return 0;
}