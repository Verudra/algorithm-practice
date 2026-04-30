#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[110];
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;;i ++){ // 枚举执行次数
        int maxn = 0, minn = 100, k = 0;
        for(int j = 1;j <= n;j ++){
            if(a[j] >= maxn){
                maxn = a[j];
                k = j;
            }
            if(a[j] <= minn && a[j] != 0){
                minn = a[j];
            }
        }
        a[k] = maxn - minn;
        if(maxn == 0){
            cout << i-1;
            break;
        }
    }
    return 0;
}