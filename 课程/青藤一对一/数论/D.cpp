#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
bool vis[N];
int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 2;i <= n;i ++){
        if(vis[i] == false){
            cnt ++;
            for(int j = 2*i;j <= n;j += i) vis[j] = true;
        }
    }
    cout << cnt;
    return 0;
}