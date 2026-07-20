#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v; 
    int t; 
    while(cin >> t){
        // if(t==-1) break;
        v.push_back(t);
    }   
    vector<int>v1;
    for(auto i : v){
        int l = 0, r = v1.size();
        while(l < r){
            int mid = l+r>>1;
            if(v1[mid] < i) l = mid+1;
            else r = mid;
        }
        if(l == v1.size()) v1.push_back(i);
        else v1[l] = i;
    }
    vector<int>v2;
    for(auto i : v){
        int l = 0, r = v2.size();
        while(l < r){
            int mid = l+r>>1;
            if(v2[mid] >= i) l = mid+1;
            else r = mid;
        }
        if(l == v2.size()) v2.push_back(i);
        else v2[l] = i;
    }
    cout << v2.size() << '\n' << v1.size();
    return 0;
}