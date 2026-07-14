#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    auto ck = [](int x){
        for(int i = 2;i*i <= x;i ++) if(!(x%i)) return false;
        return true;
    };
    int c = 0;
    for(int i = a;i <= b;i ++) if(ck(i)) c ++;
    cout << c;
    return 0;
}