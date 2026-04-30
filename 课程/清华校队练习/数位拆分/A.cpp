#include <bits/stdc++.h>
using namespace std;
int main(){
    int L,R;
    cin >> L >> R;
    auto pd = [](int num) -> bool {
        int cnt = 0;
        while(num){
            num%10==2?cnt++:0;
            num /= 10;
        }
        if(cnt == 3) return true;
        return false;
    };
    int ans = 0;
    for(int i = L;i <= R;i ++) if(pd(i)) ans ++;
    cout << ans;
    return 0;
}