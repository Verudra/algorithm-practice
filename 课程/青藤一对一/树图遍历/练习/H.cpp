#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct node{
    int ls,rs;
}tre[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> tre[i].ls >> tre[i].rs;
    }
    queue<int>q;
    q.push(1);
    bool flag = false, flag2 = false;
    while(!q.empty()){
        int t = q.front(); q.pop();
        if(tre[t].ls){
            if(flag) flag2 = true;
            q.push(tre[t].ls); 
        }
        else flag = true;
        if(tre[t].rs){
            if(flag) flag2 = true;
            q.push(tre[t].rs); 
        }
        else flag = true;
    }
    if(flag2) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}