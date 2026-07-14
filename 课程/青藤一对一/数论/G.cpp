#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n; cout << n << '=';
    queue<int>q;
    for(int i = 2;i*i <= n;i ++){
        while(n%i==0){
            q.push(i);
            n /= i;
        }
    }
    if(n>1) q.push(n);
    while(!q.empty()){
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << '*';
    }
    return 0;
}