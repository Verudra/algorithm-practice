#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int sa[N][N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        sa[i][1] = sa[i][i] = 1;
        for(int j = 2;j < i;j ++){
            sa[i][j] = sa[i-1][j] + sa[i-1][j-1];
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++) cout << sa[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}