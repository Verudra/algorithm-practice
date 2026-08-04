#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int sa[N];
int main(){
    int n,k;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    cin >> k;
    sort(sa+1,sa+1+n);
    cout << sa[n-k+1];
    return 0;
}