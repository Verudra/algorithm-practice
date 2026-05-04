#include <bits/stdc++.h>
using namespace std;
void work(){
    int n,x;
    cin >> n >> x;
    if(x == 1){
        if((n&(n-1)) == 0) cout << "Yes\n";
        else cout << "No\n";
        return ;
    }
    int C = 0,n1 = n;
    while(n1){
        C += n1%x;
        n1 /= x;
    }
    int m = 0;
    while((1<<m) <= n){
        if((1<<m) >= C && ((n-(1<<m))%(x-1)) == 0){
            cout << "Yes\n";
            return ;
        }
        m ++;
    }
    cout << "No\n";
    return ;
}
int main(){
    int T;
    cin >> T;
    while(T --){
        work();
    }
    return 0;
}