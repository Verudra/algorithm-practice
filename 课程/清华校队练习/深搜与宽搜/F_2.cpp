#include <bits/stdc++.h>
using namespace std;
int mp[10][10];
bool visx[10][10],visy[10][10],visbox[10][10];
int getbox(int x,int y){
    return (x-1)/3*3 + (y-1)/3;
}
bool dfs(int pos){
    if(pos > 81){
        for(int i = 1;i <= 9;i ++){
            for(int j = 1;j <= 9;j ++){
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = (pos-1)/9+1, y = (pos-1)%9+1;
    if(mp[x][y]) return dfs(pos+1);
    for(int i = 1;i <= 9;i ++){
        if(visx[x][i]||visy[y][i]||visbox[getbox(x,y)][i]) continue;
        visx[x][i] = visy[y][i] = visbox[getbox(x,y)][i] = true;
        mp[x][y] = i;
        if(dfs(pos+1)) return true;
        visx[x][i] = visy[y][i] = visbox[getbox(x,y)][i] = false;
        mp[x][y] = 0;
    }
    return false;
}
int main(){
    for(int i = 1;i <= 9;i ++){
        for(int j = 1;j <= 9;j ++){
            cin >> mp[i][j];
            int val = mp[i][j];
            if(val) visx[i][val] = visy[j][val] = visbox[getbox(i,j)][val] = true;
        }
    }
    dfs(1);
    return 0;
}