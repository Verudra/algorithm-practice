#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>vec;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>fa(n,-1);
    vec.resize(n);
    for(int i = 0;i < n;i ++){
        int k; scanf("%d",&k);
        for(int j = 0;j < k;j ++){
            int t; scanf("%d",&t);
            vec[i].push_back(t);
            fa[t] = i;
        }
        sort(vec[i].begin(),vec[i].end());
    }
    int rt = -1;
    for(int i = 0;i < n;i ++){
        if(fa[i] == -1) rt = i;
    }
    queue<pair<int,int>>q;
    q.push({rt,1});
    int maxn = -1, maxpos = -1;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(now.second > maxn){
            maxn = now.second;
            maxpos = now.first;
        }
        for(auto v : vec[now.first]){
            q.push({v,now.second+1});
        }
    }
    stack<int>stk;
    while(fa[maxpos] != -1){
        stk.push(maxpos);
        maxpos = fa[maxpos];
    }
    stk.push(maxpos);
    printf("%d\n",maxn);
    while(!stk.empty()){
        printf("%d",stk.top());
        stk.pop();
        if(!stk.empty()) printf(" ");
    }
    return 0;
}