#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int sa[N][N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cin >> sa[i][j];
            if(i == j) sa[i][j] += 10;
            else if(i+j == n+1) sa[i][j] += 10; 
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout << sa[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}