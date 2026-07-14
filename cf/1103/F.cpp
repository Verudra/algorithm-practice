#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
vector<int>fac(MAX+5);
vector<int>prime;
void init(){
    fac[1] = 1;
    for(int i = 2;i <= MAX;i ++){
        if(fac[i] == 0) prime.push_back(i), fac[i] = i;
        for(int j : prime){
            if(j > fac[i] || j*i > MAX) break;
            if(fac[i*j] == 0) fac[i*j] = i;
        }
    }
}

int main(){

}