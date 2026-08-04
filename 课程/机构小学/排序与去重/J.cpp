#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N];
int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        for(int i = 1;i <= n;i ++) cin >> sa[i];
        sort(sa+1,sa+1+n);
        int sum = 0;
        for(int i = 1;i <= n/2+1;i ++){
            sum += sa[i]/2+1;
        }
        cout << sum << '\n';
    }
    return 0;
}