#include <bits/stdc++.h>
using namespace std;
int a,b,c;
map<pair<int,int>,bool>mp;
struct node{
    int x,y,cnt;
};
int main(){
    cin >> a >> b >> c;
    queue<node>q;
    bool flag = false;
    q.push({0,0,0});
    while(!q.empty()){
        auto now = q.front();
        int x = now.x, y = now.y, cnt = now.cnt;
        q.pop();
        if(now.x == c || now.y == c){
            flag = true;
            cout << now.cnt;
            break;
        }
        if(!mp[{a,y}]) q.push({a,y,cnt+1}),mp[{a,y}] = true;
        if(!mp[{x,b}]) q.push({x,b,cnt+1}),mp[{x,b}] = true;
        if(!mp[{max(0,x+y-b),min(b,x+y)}]) q.push({max(0,x+y-b),min(b,x+y),cnt+1}), mp[{max(0,x+y-b),min(b,x+y)}] = true;
        if(!mp[{min(x+y,a),max(x+y-a,0)}]) q.push({min(x+y,a),max(x+y-a,0),cnt+1}), mp[{min(x+y,a),max(x+y-a,0)}] = true;
        if(!mp[{0,y}]) q.push({0,y,cnt+1}), mp[{0,y}] = true;
        if(!mp[{x,0}]) q.push({x,0,cnt+1}), mp[{x,0}] = true;
    }
    if(!flag) cout << "No Solution!";
    return 0;
}