#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i = 1;i <= n;i ++){
        cin >> v[i];
    }
    for(int i = n;;i ++){
        unordered_map<int,bool>mp;
        bool flag = false;
        for(int j = 1;j <= n;j ++){
            if(mp[v[j]%i] == true){
                flag = true;
                break;
            }
            else mp[v[j]%i] = true;
        }
        if(!flag){
            cout << i;
            break;
        }
    }
    return 0;
}