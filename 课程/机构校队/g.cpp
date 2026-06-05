#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int sa[N], b[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    int maxn = -1, minn = 1e4+10, sum = 0;
    for(int i = 1;i <= n;i ++){
        maxn = max(maxn, sa[i]);
        minn = min(minn, sa[i]);
        sum += sa[i];
    }
    sort(sa+1,sa+1+n,[](int a,int b){return a > b;});
    int j = 0; b[++j] = sa[1];
    for(int i = 2;i <= n;i ++){
        if(sa[i] != sa[i-1]) b[++j] = sa[i];
    }
    // sort(b+1,b+1+j,[](int a,int b){return a > b;});
    cout << sum << '\n' << maxn << '\n' << minn << '\n';
    for(int i = 1;i <= j;i ++) cout << b[i] << ' ';
    return 0;
}