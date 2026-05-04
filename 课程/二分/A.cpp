#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l = 1, r = 100;
    while(l < r){
        int mid = l+r>>1;
        cout << mid << '\n';
        if(mid >= n) r = mid;
        else l = mid+1;
    }
    if(l == n) cout << "成功！";
    else cout << "失败！";
    return 0;
}