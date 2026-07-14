#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    while(n != 495){
        int sa[] = {n/100, n/10%10, n%10};
        sort(sa+0,sa+2+1,[](int a,int b){return a < b;});
        int t1 = 0, t2 = 0;
        for(int i = 0;i < 3;i ++) t1 = t1*10+sa[i];
        sort(sa+0,sa+2+1,[](int a,int b){return a > b;});
        for(int i = 0;i < 3;i ++) t2 = t2*10+sa[i];
        cnt ++;
        n = t2-t1;
    }
    cout << cnt;
    return 0;
}