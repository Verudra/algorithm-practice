#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int sa[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    sort(sa+1,sa+1+n);
    int ans1 = -1, ans2 = -1;
    for(int i = 2;i <= n;i ++){
        if(sa[i] == sa[i-1]) ans2 = sa[i];
        if(sa[i]-sa[i-1] > 1) ans1 = sa[i]-1;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}