#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    while(n --){
        ll t; cin >> t;
        auto ts = [](int x){
            x *= 7;
            while(x>9){
                int t = 0;
                while(x) t+=x%10,x/=10;
                x = t;
            }
            return x;
        };
        auto ck = [&](ll x)->bool {
            // stack<int>stk;
            int s = 0;
            bool f = true;
            while(x){
                if(f) s += (ts(x%10));
                else s += (x%10);
                x /= 10;
                f = !f;
            }
            return !(s%8);
        };
        if(ck(t)) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}