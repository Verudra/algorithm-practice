#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n);
    int sum = 0;
    for(auto& i : vec) scanf("%d",&i),sum+=i;
    sum /= n;
    int ans = 0;
    for(int i = 0;i < vec.size();i ++){
        if(vec[i] != sum) ans ++;
        if(i!=vec.size()-1) vec[i+1] += vec[i]-sum;
    }
    printf("%d",ans);
    return 0;
}