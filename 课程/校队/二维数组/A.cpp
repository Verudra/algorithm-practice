#include <bits/stdc++.h>
using namespace std;
const int N = 6;
int sa[N][N];
int mx[N][N];
int mi[N][N];

int main(){
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> sa[i][j];
        }
    }
    for(int i = 1;i <= 5;i ++){
        int maxn = 0, maxpos = 0;
        for(int j = 1;j <= 5;j ++){
            if(sa[i][j] > maxn){
                maxn = sa[i][j];
                maxpos = j;
            }
        }
        mx[i][maxpos] = 1;
    }
    for(int j = 1;j <= 5;j ++){
        int minn = 1e9, minpos = 0;
        for(int i = 1;i <= 5;i ++){
            if(sa[i][j] < minn){
                minn = sa[i][j];
                minpos = i;
            }
        }
        mi[minpos][j] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= 5;i ++){
        for(int j = 1;j <= 5;j ++){
            if(mx[i][j] == 1 && mi[i][j] == 1){
                cout << i << ' ' << j << ' ' << sa[i][j] << '\n';
                cnt ++;
            }
        }
    }
    if(cnt == 0) cout << "not found";
    return 0;
}