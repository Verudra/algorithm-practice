#include<bits/stdc++.h>
using namespace std;
struct{
    int cnt[26];
    string getS(string s){
        for(auto& i : s) if(i >= 'a' && i <= 'z') i += 'A'-'a';
        return s;
    }
    void put(string s){
        s = getS(s);
        for(auto& i:s) cnt[i-'A'] ++;
    }
    void out(){
        vector<pair<int,char>>vec;
        for(int i = 0;i < 26;i ++) if(cnt[i]) vec.push_back({cnt[i],'A'+i});
        sort(vec.begin(),vec.end(),[](auto a,auto b){return a.first!=b.first?a.first>b.first:a.second<b.second;});
        for(auto& i : vec) cout << i.second << ' ' << i.first << '\n';
        return ;
    }
}ANS;
int main(){
    string s;
    cin >> s;
    ANS.put(s);
    ANS.out();
    return 0;
}