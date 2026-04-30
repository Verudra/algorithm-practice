#include<bits/stdc++.h>
using namespace std;
int main(){
    int m; cin >> m;
    vector<string>vec(m);
    for(auto& i : vec) cin >> i;
    auto getans = [](string ss) -> array<int,4> {
        auto res = (array<int,4>){1,1,1,1};
        auto pd16 = [](char c) -> bool {
            if(c >= 'A' && c <= 'F' || c >= '0' && c <= '9') return true;
            return false;
        };
        for(auto i : ss){
            if(!pd16(i)) res = {0,0,0,0};
            if(i > '9' || i < '0') res[0] = res[1] = res[2] = 0;
            if(i >= '2') res[0] = 0;
            if(i >= '8') res[1] = res[0] = 0;
        }
        return res;
    };
    for(auto s : vec){
        auto res = getans(s);
        printf("%d %d %d %d\n",res[0],res[1],res[2],res[3]);
    }
    return 0;
}