#include <bits/stdc++.h>
using namespace std;
int n;
bool flag = false;
vector<int>ans;
vector<int>vec;
bool check_nd(vector<int>&vv){
    for(int i = 1;i < vv.size();i ++){
        if(vec[vv[i]] < vec[vv[i-1]]) return false;
    }
    return true;
}
bool check_pd(vector<int>&vv){
    for(int i = 0;i < vv.size();i ++){
        if(vv[i] != vv[vv.size()-i-1]) return false;
    }
    return true;
}
void dfs(int pos,vector<int>&v1,vector<int>&v2){
    // v1 removed element
    if(pos == n){
        if(check_nd(v1) && check_pd(v2)) ans = v1, flag = true;
        return ;
    }
    v1.push_back(pos);
    dfs(pos+1,v1,v2);
    v1.pop_back();
    v2.push_back(vec[pos]);
    dfs(pos+1,v1,v2);
    v2.pop_back();
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        flag = false;
        vec.clear();
        ans.clear();
        scanf("%d",&n);
        getchar();
        vector<int>sa1,sa2;
        for(int i = 1;i <= n;i ++){
            char c = getchar();
            if(c == '0') vec.push_back(0);
            else vec.push_back(1);
        }
        dfs(0,sa1,sa2);
        if(flag == false) printf("-1");
        else{
            printf("%d\n",ans.size());
            for(auto i : ans) printf("%d ",i+1);
        }
        printf("\n");
    }
    return 0;
}