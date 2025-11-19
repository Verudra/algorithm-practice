#include <bits/stdc++.h>
using namespace std;
map<vector<int>,int>mp;
bool cmp(pair<int,vector<int>> a, pair<int,vector<int>> b){
    if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++){
        vector<int>vec;
        for(int j = 1;j <= m;j ++){
            int t; scanf("%d",&t);
            vec.push_back(t);
        }
        mp[vec] ++;
    }
    vector<pair<int,vector<int>>> ans;
    for(auto i : mp){
        ans.push_back({i.second,i.first});
    }
    // sort(ans.begin(),ans.end(),[](pair<int,vector<int>> a, pair<int,vector<int>> b){
    //     if(a.first != b.first) return a.first > b.first;
    //     return a.second < b.second;
    // });
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",(int)ans.size());
    for(auto i : ans){
        printf("%d ", i.first);
        for(int j = 0;j < (int)i.second.size();j ++){
            printf("%d", i.second[j]);
            if(j != (int)i.second.size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}