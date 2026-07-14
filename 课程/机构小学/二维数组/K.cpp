#include <bits/stdc++.h>
using namespace std;
const int N = 6;
int sa[N][N];
bool maxf[N][N];
int main(){
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> sa[i][j];
        }
    }
    for(int i = 1;i <= 5;i ++){
        int ma = 1;
        for(int j = 1;j <= 5;j ++){
            if(sa[i][j] > sa[i][ma]) ma = j;
        }
        maxf[i][ma] = true;
    }
    for(int j = 1;j <= 5;j ++){
        int mi = 1;
        for(int i = 1;i <= 5;i ++){
            if(sa[i][j] < sa[mi][j]) mi = i;
        }
        if(maxf[mi][j]){
            cout << mi << ' ' << j << ' ' << sa[mi][j] << '\n';
            return 0;
        }
    }
    cout << "not found";
    return 0;
}