#include <bits/stdc++.h>
using namespace std;
const int N = 20;
bool l[N],d1[N],d2[N];
int ans[N];
int n,cnt = 0;
void dfs(int now){
    if(now > n){
        if(cnt < 3){
            for(int i = 1;i <= n;i ++){
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
        cnt ++;
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(!l[i] && !d1[i-now+N] && !d2[i+now]){
            ans[now] = i;
            l[i] = d1[i-now+N] = d2[i+now] = true;
            dfs(now+1);
            l[i] = d1[i-now+N] = d2[i+now] = false;
        }
    }
    return ;
}
int main(){
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
}