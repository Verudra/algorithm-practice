#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>stk;
    string s;
    cin >> s;
    int n;
    scanf("%d",&n);
    for(auto i : s){
        while(!stk.empty() && i < stk.top() && n > 0){
            stk.pop();
            n --;
        }
        if(i == '0') ;
        else stk.push(i);
    }
    while(n > 0){
        stk.pop();
        n --;
    }
    stack<int>stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    while(!stk2.empty()){
        printf("%c",stk2.top());
        stk2.pop();
    }
    return 0;
}