#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; vector<double>v;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        double t; cin >> t;
        v.push_back(t);
    }
    auto getavg = [](vector<double>v){
        double res = 0;
        for(auto i : v) res += i;
        return res/(v.size()*1.0);
    };
    double avg = getavg(v);
    cout << fixed << setprecision(1) << avg << '\n';
    for(int i = 0; i < v.size();i ++){
        if(v[i] > avg) cout << fixed << setprecision(0) << i+1 << ':' << v[i] << ' ';
    }
    return 0;
}