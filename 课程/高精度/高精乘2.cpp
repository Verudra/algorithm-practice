#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int> &A, vector<int> &B){
    vector<int>C(A.size()+B.size(),0);
    for(int i = 0;i < A.size();i ++){
        for(int j = 0;j < B.size();j ++){
            C[i+j] += A[i]*B[j];
        }
    }
    int t = 0;
    for(int i = 0;i < A.size()+B.size();i ++){
        t += C[i];
        C[i] = t%10;
        t /= 10;
    }
    while(C.size()!=0 && C.back()==0) C.pop_back();
    return C;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>A(1,2), B(1,2);
    for(int i = 1;i < n;i ++) A = mul(A,B);
    for(int i = A.size()-1;i >= 0;i --) cout << A[i];
    return 0;
}