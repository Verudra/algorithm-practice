#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int sa[N][N];
int tx[] = {-1,-1,-1,0,0,1,1,1}, ty[] = {-1,0,1,-1,1,-1,0,1};
int main(){
    int h,l,c,r;
    cin >> h >> l >> c >> r;
    c ++; r ++;
    for(int i = 1;i <= h;i ++){
        for(int j = 1;j <= l;j ++){
            cin >> sa[i][j];
        }
    }
    int s = 0;
    for(int i = 0;i < 8;i ++){
        s += sa[c+tx[i]][r+ty[i]];
    }
    cout << s;
    return 0;
}