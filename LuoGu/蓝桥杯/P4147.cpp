#include <bits/stdc++.h>
using namespace std;
bool pd(char c){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
    return false;
}
char read(){
    char c = getchar();
    while(!pd(c)) c = getchar();
    return c;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> v(n,vector<int>(m,0));
    vector<int>ht(m+1);
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            char c = read();
            if(c == 'F'){
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i ++){
        stack<int>stk;
        for(int j = 0;j < m;j ++){
            if(v[i][j] == 1) ht[j] ++;
            else ht[j] = 0;
        }
        for(int j = 0;j <= m;j ++){
            while(!stk.empty() && ht[stk.top()] >= ht[j]){
                int h = ht[stk.top()];
                stk.pop();
                int w = stk.empty()?j:j-1-stk.top();
                ans = max(ans, h*w);
            }
            stk.push(j);
        }
    }
    printf("%d",ans*3);
    return 0;
}