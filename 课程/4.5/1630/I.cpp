#include<bits/stdc++.h>
using namespace std;
map<char,int>mp; // -1 不亮 1 常亮 0 没证据有问题
map<char,map<char,bool>>pd;
void add(char c,string s){ // 加亮
    for(auto i : s) pd[c][i] = true;
}
map<char,bool> getmap(string s){
    map<char,bool>mp;
    for(auto i : s) mp[i] = true;
    return mp;
}
void init(){
    add('0',"ABCDEF");
    add('1',"BC");
    add('2',"ABGED");
    add('3',"ABGCD");
    add('4',"FGBC");
    add('5',"AFGCD");
    add('6',"AFGECD");
    add('7',"ABC");
    add('8',"ABCDEFG");
    add('9',"ABGFCD");
}
int main(){
    int n;
    init();
    scanf("%d",&n);
    getchar();
    for(int i = 1;i <= n;i ++){
        char k = getchar();
        string ss;
        getline(cin,ss);
        auto pd1 = [](char c,string s){
            auto now = pd[c];
            for(auto i : s) if(!now[i]) mp[i] = 1;
        };
        auto pd2 = [](char c,string s){
            auto now = pd[c];
            map<char,bool>mmp = getmap(s);
            for(auto [a,b]:now){
                if(b && mmp[a] == false) mp[a] = -1;
            }
        };
        pd1(k,ss);pd2(k,ss);
    }
    for(int i = 0;i < 7;i ++){
        if(mp[i+'A'] == -1) printf("x");
        else if(mp[i+'A'] == 1) printf("X");
        else printf("-");
    }
    return 0;
}