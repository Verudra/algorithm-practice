#include <bits/stdc++.h>
using namespace std;
unordered_map<string,string>mp1,mp2;
int main(){
    int n;
    cin >> n;
    vector<string>v;
    for(int i = 1;i <= n;i ++){
        string s1,s2;
        cin >> s1 >> s2;
        mp1[s1] = s2;
        mp2[s2] = s1;
        v.push_back(s1);
    }
    int ans = 0;
    for(auto s : v){
        if(s == mp2[mp1[s]])
    }
}