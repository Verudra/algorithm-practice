#include <bits/stdc++.h>
using namespace std;
const int N = 6;
int sa[N][N];
int main(){
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> sa[i][j];
        }
    }
    int n,m; cin >> n >> m;
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j ++){
            int x = i, y = j;
            if(i == n) x = m;
            else if(i == m) x = n;
            cout << sa[x][y] << ' ';
        }
        cout << '\n';
    }
    return 0;
}