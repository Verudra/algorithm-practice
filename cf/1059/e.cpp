#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
bool vis[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i ++) vis[i] = false;
        int t;
        vector<int>vec;
        for(int i = 1;i <= n;i ++){
            scanf("%d",&t);
            vec.push_back(t);
            vis[t] = true;
        }
        int unpnum = -1;
        for(int i = 1;i <= n;i ++){
            if(vis[i] == false){
                unpnum = i;
                break;
            }
        }
        if(~unpnum){
            int fst = -1;
            for(int i = 1;i <= n;i ++){
                if(i != unpnum && i != *vec.rbegin()){
                    fst = i;
                    break;
                }
            }
            for(int i = 1;i <= k;i ++){
                switch((i-1)%3){
                    case 0:
                        printf("%d ",unpnum);
                        break;
                    case 1:
                        printf("%d ",fst);
                        break;
                    case 2:
                        printf("%d ",*vec.rbegin());
                        break;
                }
            }
            printf("\n");
        }
        else{
            for(int i = 1;i <= k;i ++){
                printf("%d ",vec[(i-1)%3]);
            }
            printf("\n");
        }
    }
    return 0;
}