#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N][N];
int main(){
    int n;cin >> n;
    int s = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cin >> sa[i][j];
            if(i <= n/2) s += sa[i][j];
        }
    }
    cout << s;
    return 0;
}