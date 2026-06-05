#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int mp[N][N];
int dr[N][N];
int n,m,q;
bool check(int x,int y,int tx,int ty){
    for(int i = 1;i <= tx;i ++){
        for(int j = 1;j <= ty;j ++){
            int tox = x+i-1,toy = y+j-1;
            if(dr[i][j] == 1){
                if(tox > n || tox < 1 || toy > m || toy < 1) return false;
                if(mp[tox][toy] == 1) return false; 
            }
        }
    }
    return true;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i <= q;i ++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        getchar();
        int x,y;
        bool flag = false;
        const int inf = 0x3f3f3f3f;
        int minx=inf,miny=inf,maxx=-inf,maxy=-inf;
        int bdr[N][N] = {0};
        for(int j = 1;j <= t1;j ++){
            for(int k = 1;k <= t2;k ++){
                char c = getchar();
                if(c == '*'){
                    minx = min(minx,j);
                    miny = min(miny,k);
                    maxx = max(maxx,j);
                    maxy = max(maxy,k);
                    dr[j][k] = 1;
                    bdr[j][k] = 1;
                    if(flag == false){
                        flag = true;
                        x = j,y = k;
                    }
                }
            }
            getchar();
        }
        x -= minx-1,y -= miny-1;
        for(int j = minx;j <= maxx;j ++){
            for(int k = miny;k <= maxy;k ++){
                int tox = j-minx+1, toy = k-miny+1;
                dr[tox][toy] = bdr[j][k];
            }
        }
        int tx = maxx-minx+1, ty = maxy-miny+1;
        flag = false;
        int ansx = 0,ansy = 0;
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= m;k ++){
                if(check(j,k,tx,ty)){
                    ansx = j+x-1,ansy = k+y-1;
                    for(int o1 = 1;o1 <= tx;o1 ++){
                        for(int o2 = 1;o2 <= ty;o2 ++){
                            if(dr[o1][o2] == 1) mp[j+o1-1][k+o2-1] = 1;
                        }
                    }
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        if(flag == false) printf("-1 -1\n");
        else printf("%d %d\n",ansx,ansy);
    }
    return 0;
}