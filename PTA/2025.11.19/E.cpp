#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>vec(24);
    for(auto& i : vec){
        scanf("%d",&i);
    }
    int t;
    // (1 < 2) (a < b)
    int a = 0;
    while(cin >> t){
        if(t > 23 || t < 0) break;
        if(vec[t] > 50) printf("%d Yes\n",vec[t]);
        else printf("%d No\n",vec[t]);
    }
    return 0;
}