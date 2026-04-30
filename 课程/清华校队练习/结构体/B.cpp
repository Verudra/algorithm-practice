#include <bits/stdc++.h>
using namespace std;
struct Stu{
    string id;
    double sc;
    bool operator<(const Stu b){
        return sc < b.sc;
    }
    Stu(){
        cin >> id >> sc;
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<Stu>vec;
    for(int i = 1;i <= n;i ++) vec.push_back(Stu());
    sort(vec.begin(),vec.end());
    cout << vec[vec.size()-k].id << ' ' << vec[vec.size()-k].sc;
    return 0;
}