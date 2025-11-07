#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
    for(int i = 2;i*i <= x;i ++){
        if(x%i == 0) return false;
    }
    return true;
}
bool vis[30];
int n;
int ans = 0;
void dfs(vector<int>&vec){
    if(vec.size() == n){
        if(isprime(vec.front()+vec.back())) ans ++;
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(vis[i] == false){
            if(isprime(vec.back()+i)){
                vis[i] = true;
                vec.push_back(i);
                dfs(vec);
                vec.pop_back();
                vis[i] = false;
            }
        }
    }
}
int main(){
    while(cin >> n){
        ans = 0;
        vector<int>vec;
        vec.push_back(1);
        vis[1] = true;
        dfs(vec);
        printf("%d\n",ans);
    }
    return 0;
}