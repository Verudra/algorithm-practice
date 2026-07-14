#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char mp[N][N];
int main(){
    int h,w,lx,ly,rx,ry;
    cin >> h >> w >> lx >> rx >> ly >> ry;
    for(int i = 1;i <= h;i ++){
        for(int j = 1;j <= w;j ++){
            cin >> mp[i][j];
        }
    }
    for(int i = lx;i <= rx;i ++){
        for(int j = ly;j <= ry;j ++){
            cout << mp[i][j];
        }
        cout << '\n';
    }
    return 0;
}