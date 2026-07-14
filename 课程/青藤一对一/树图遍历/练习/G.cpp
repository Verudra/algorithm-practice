#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    int ls,rs;
}tre[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        auto& t = tre[i];
        cin >> t.ls >> t.rs;
    }
    queue<int>q;
    q.push(1);
    vector<int>ans;
    while(!q.empty()){
        int now = q.front(); q.pop();
        ans.push_back(now);
        if(tre[now].ls) q.push(tre[now].ls);
        if(tre[now].rs) q.push(tre[now].rs);
    }
    for(auto i : ans) cout << i << ' ';
    return 0;
}