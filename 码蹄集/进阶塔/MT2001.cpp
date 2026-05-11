#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(3);
    for(int i = 1;i <= n;i ++){
        int t;
        cin >> t;
        v[t%3] ++;
    }
    cout << min(v[1],v[2]) + v[0]/2;
    return 0;
}