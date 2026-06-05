#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int mp[N][N];
bool row[N][N], col[N][N], box[N][N];
vector<pair<int,int>> blank;

int readCell(char ch){
    if(ch == '?' || ch == '.' || ch == '0') return 0;
    return ch-'0';
}

int getBox(int x, int y){
    return (x-1)/3*3+(y-1)/3+1;
}

bool dfs(int now){
    if(now == (int)blank.size()){
        for(int i = 1;i <= 9;i ++){
            for(int j = 1;j <= 9;j ++){
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    int best = now, bestCnt = 10;
    for(int i = now;i < (int)blank.size();i ++){
        int x = blank[i].first, y = blank[i].second;
        int b = getBox(x,y), cnt = 0;
        for(int val = 1;val <= 9;val ++){
            if(!row[x][val] && !col[y][val] && !box[b][val]){
                cnt ++;
            }
        }
        if(cnt < bestCnt){
            bestCnt = cnt;
            best = i;
        }
        if(bestCnt == 1) break;
    }
    if(bestCnt == 0) return false;

    swap(blank[now],blank[best]);
    int x = blank[now].first, y = blank[now].second;
    int b = getBox(x,y);
    for(int val = 1;val <= 9;val ++){
        if(!row[x][val] && !col[y][val] && !box[b][val]){
            row[x][val] = col[y][val] = box[b][val] = true;
            mp[x][y] = val;
            if(dfs(now+1)) return true;
            mp[x][y] = 0;
            row[x][val] = col[y][val] = box[b][val] = false;
        }
    }
    swap(blank[now],blank[best]);
    return false;
}
int main(){
    char ch;
    bool firstCase = true;
    while(cin >> ch){
        memset(mp,0,sizeof mp);
        memset(row,0,sizeof row);
        memset(col,0,sizeof col);
        memset(box,0,sizeof box);
        blank.clear();

        bool ok = true;
        for(int pos = 0;pos < 81;pos ++){
            if(pos && !(cin >> ch)) return 0;
            int i = pos/9+1, j = pos%9+1;
            mp[i][j] = readCell(ch);
            if(mp[i][j]){
                int b = getBox(i,j), val = mp[i][j];
                if(row[i][val] || col[j][val] || box[b][val]){
                    ok = false;
                }
                row[i][val] = col[j][val] = box[b][val] = true;
            }
            else{
                blank.push_back({i,j});
            }
        }

        if(!firstCase) cout << '\n';
        firstCase = false;
        if(ok) dfs(0);
    }
    return 0;
}
