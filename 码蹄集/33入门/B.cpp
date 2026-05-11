#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int op = (a&1)+(b&1)+(c&1);
    if(op == 3) cout << "odd";
    else if(op == 0) cout << "even";
    else if(op == 1) cout << (a&1?a:((b&1)?b:c));
    else cout << (a&1?((b&1)?c:b):a);
    return 0;
}