#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>v; while(n){v.push_back(n%10); n/=10;}
    sort(v.begin(),v.end());
    auto getnum = [](vector<int> v){
        int res = 0;
        for(auto i : v) res = res*10 + i;
        return res;
    };
    int minn = getnum(v);
    sort(v.begin(),v.end(),[](int a,int b){return a > b;});
    int maxn = getnum(v);
    cout << maxn - minn;
    return 0;
}