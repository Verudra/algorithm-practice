#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int sa[N][N];
int main(){
    int n; cin >> n;
    int f = 1;
    for(int i = 1;i <= n;i ++){
        sa[i][i] = (f==0?f=1:f=0);
        int x = i, y = i;
        while(x >= 1) sa[x--][y] = sa[i][i];
        x = i;
        while(y >= 1) sa[x][y--] = sa[i][i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++) cout << sa[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}