#include<bits/stdc++.h>
using namespace std;
int sa[25][25];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cin >> sa[i][j];
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(i==j || i+j==n+1) sa[i][j] += 10;
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++) cout << sa[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}