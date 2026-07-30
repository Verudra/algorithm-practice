#include <bits/stdc++.h>
using namespace std;
int sa[105][105], mp[105][105];
int main(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> sa[i][j];
        }
    }
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            mp[i][j] = sa[n-j+1][i];
        }
    }
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}