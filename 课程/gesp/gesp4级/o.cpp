#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int sa[N][N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> sa[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n-1;i ++){
        for(int j = 1;j <= m-1;j ++){
            if(sa[i][j]*sa[i+1][j+1]==sa[i+1][j]*sa[i][j+1]) cnt ++;
        }
    }
    cout << cnt;
    return 0;
}