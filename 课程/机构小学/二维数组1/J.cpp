#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N][N];
int tx[] = {-1,1,0,0};
int ty[] = {0,0,-1,1};
int main(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> sa[i][j];
        }
    }
    for(int i = 2;i < n;i ++){
        for(int j = 2;j < m;j ++){
            bool flag = false;
            for(int k = 0;k < 4;k ++){
                int px = i+tx[k], py = j+ty[k];
                if(sa[i][j] >= sa[px][py]) flag = true;
            }
            if(!flag) cout << sa[i][j] << '\n';
        }
    }
    return 0;
}