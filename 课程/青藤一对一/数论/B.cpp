#include <bits/stdc++.h>
using namespace std;
int main(){
    auto pd = [](int x){
        int tx = x;
        queue<int>q; while(x){q.push(x%10);x/=10;}
        int res = 0;
        while(!q.empty())  res += pow(q.front(),3),q.pop();
        return res == tx;
    };
    for(int i = 100;i <= 999;i ++){
        if(pd(i)) cout << i << '\n';
    }
    return 0;
}