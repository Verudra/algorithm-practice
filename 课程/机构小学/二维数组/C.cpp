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
    for(int i = 5;i >= 1;i --){
        for(int j = 1;j <= 5;j ++){
            cout << sa[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}