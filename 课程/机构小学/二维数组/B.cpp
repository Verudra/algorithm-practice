#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N][N];
int main(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> sa[i][j];
        }
    }
    for(int j = 1;j <= m;j ++){
        for(int i = n;i >= 1;i --){
            cout << sa[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}   