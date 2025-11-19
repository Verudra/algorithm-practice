#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    stack<char>stk;
    queue<char>q[105];
    for(int i = 1;i <= n;i ++){
        string s;
        cin >> s;
        for(auto c : s){
            q[i].push(c);
        }
    }
    int t;
    while(cin >> t){
        if(t == -1) break;
        if(t == 0){
            if(!stk.empty()){
                printf("%c",stk.top());
                stk.pop();
            }
        }
        else{
            if(q[t].empty()) continue;
            while((int)stk.size() >= s){
                printf("%c",stk.top());
                stk.pop();
            }
            stk.push(q[t].front());
            q[t].pop();
        }
    }
    return 0;
}