#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int sa[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    int maxn = 0;
    for(int i = 1;i <= n;i ++){
        int cnt = 1, now = sa[i];
        for(int j = i+1;j <= n;j ++){
            if(sa[j] < now) break;
            cnt ++;
            now = sa[j];
        }
        maxn = max(maxn, cnt);
    }
    cout << maxn;
    return 0;
}