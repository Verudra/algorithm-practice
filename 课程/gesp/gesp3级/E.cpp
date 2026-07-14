#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,i; cin >> n >> i;
    if(n == 1){
        cout << 1+i;
        return 0;
    }
    ll a = 1;
    while(1){
        ll fish = a;
        bool f = 1;
        for(int j = 1;j < n;j ++){
            if((fish+i)%(n-1)){
                f = 0;
                break;
            }
            fish = (fish*n+i)/(n-1);
        }
        if(f){
            cout << fish*n+i;
            return 0;
        }
        a ++;
    }
    return 0;
}