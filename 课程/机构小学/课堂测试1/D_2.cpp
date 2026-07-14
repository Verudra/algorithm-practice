#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int sa[N];
int main(){
    int nn;
    cin >> nn;
    int minn = N, maxn = -1;
    for(int i = 1;i <= nn;i ++){
        cin >> sa[i];
        if(minn > sa[i]) minn = sa[i];
        if(maxn < sa[i]) maxn = sa[i];
    }
    int m = -1,n = -1;
    for(int i = minn;i <= maxn;i ++){
        int cnt = 0;
        for(int j = 1;j <= nn;j ++){
            if(sa[j] == i) cnt ++;
        }
        if(cnt == 0) m = i;
        if(cnt > 1) n = i;
    }
    cout << m << ' ' << n;
    return 0;
}