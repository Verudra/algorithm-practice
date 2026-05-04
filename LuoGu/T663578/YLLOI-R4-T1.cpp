#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,d;
    cin >> n >> m >> d;
    if((d+1)*n > m){
        cout << "-1";
    }
    else{
        if(m-(d+1)*n <= n) cout << m-(d+1)*n;
        else cout << (m-(d+1)*n-n)/(d+1)+n;
    }
    return 0;
}