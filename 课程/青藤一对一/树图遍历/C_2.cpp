#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int sa[N], pos = 0, u = 1; 
void dfs(){
    if(u > pos) return ;
    int x = sa[u ++];
    if(!x){
        cout << x << ' ';
        return ;
    }
    dfs();
    cout << x << ' ';
    dfs();
    return ;
}
int main(){
    while(cin >> sa[++pos]);
    dfs();
    return 0;
}