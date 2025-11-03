#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int>fac[N];
bool vis[N];
void work(){
    int n;
    scanf("%d",&n);
    vector<int>sa1(n+1),sa2(n+1),cnt(N);
    for(int i = 1;i <= n;i ++) scanf("%d",&sa1[i]);
    for(int i = 1;i <= n;i ++) scanf("%d",&sa2[i]);
    for(int i = 1;i <= n;i ++){
        for(auto j : fac[sa1[i]]){
            cnt[j] ++;
        }
    }
    bool flag = false;
    // int ts;
    for(int i = 2;i < N;i ++){
        // printf("now:%d cnt:%d\n",i,cnt[i]);
        if(cnt[i] >= 2){
            flag = true;
            break;
        }
    }
    // printf("!");
    if(flag){
        printf("0\n");
        return ;
    }
    for(int i = 1;i <= n;i ++){
        for(auto j : fac[sa1[i]]) cnt[j] --;
        for(auto j : fac[sa1[i]+1]){
            if(cnt[j] >= 1){
                flag = true;
                break;
            }
        }
        for(auto j : fac[sa1[i]]) cnt[j] ++;
    }
    if(flag){
        printf("1\n");
        return ;
    }
    printf("2\n");
    return ;
}
void init(){
    for(int i = 2;i < N;i ++){
        if(vis[i] == false){
            for(int j = i;j < N;j += i){
                vis[j] = true;
                fac[j].push_back(i);
            }
        }
    }
    return ;
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T --){
        work();
    }
    return 0;
}