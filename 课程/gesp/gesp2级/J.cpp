#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mt = 1;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        mt *= t;
        if(mt > 1e6){
            cout << ">1000000";
            return 0;
        }
    }
    cout << mt;
    return 0;
}