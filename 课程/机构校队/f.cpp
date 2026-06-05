#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int j = 0;
    b[++j] = a[1];
    for(int i = 2;i <= n;i ++){
        if(a[i] != a[i-1]) b[++j] = a[i];
    }
    cout << b[k];
    return 0;
}