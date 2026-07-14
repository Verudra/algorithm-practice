#include <bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    while(m --){
        int t; cin >> t;
        int t2 = t;
        vector<int>v;
        while(t) v.push_back(t%10),t/=10;
        int mc = v.size(), c = 0;
        for(auto i : v) c += pow(i,mc);
        if(c == t2) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}