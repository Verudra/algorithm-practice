#include <bits/stdc++.h>
using namespace std;
int main(){
    int a1,a2,n;
    scanf("%d%d%d",&a1,&a2,&n);
    vector<int>vec = {a1,a2};
    for(int i = 0;i < n;i ++){
        printf("%d",vec[i]);
        if(i != n-1) printf(" ");
        int res = vec[i]*vec[i+1];
        if(!res) vec.push_back(0);
        else{
            stack<int>stk;
            while(res){
                stk.push(res%10);
                res /= 10;
            }
            while(!stk.empty()){
                vec.push_back(stk.top());
                stk.pop();
            }
        }
    }
    return 0;
}