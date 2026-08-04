#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
int sa[N];
int main(){
    int n,b;
    cin >> n >> b;
    for(int i = 1;i <= n;i ++) cin >> sa[i];
    sort(sa+1,sa+1+n,[](int a,int b){return a > b;});
    for(int i = 1;i <= n;i ++){
        b -= sa[i];
        if(b <= 0){
            cout << i;
            break;
        }
    }
    return 0;
}