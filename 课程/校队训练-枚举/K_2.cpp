#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 2025;
    for(int i = 1;;i ++){
        x -= 5;
        if(i&1) x -= 15; 
        else x -= 2;
        if(i%3 == 1) x -= 2;
        else if(i%3 == 2) x -= 10;
        else x -= 7;
        if(x <= 0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}