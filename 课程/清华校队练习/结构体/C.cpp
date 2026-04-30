#include <bits/stdc++.h>
using namespace std;
struct Stu{
    static int cnt;
    char name[16];
    int chi,ma,en,id;
    Stu(){cin >> name >> chi >> ma >> en;id=++cnt;}
    int sum()const{return chi+ma+en;}
    bool operator<(const Stu& b){return sum()!=b.sum()?this->sum()>b.sum():id<b.id;}
};
int Stu::cnt = 0;
int main(){
    int N; cin >> N;
    vector<Stu>vec;
    while(N --) vec.push_back(Stu());
    sort(vec.begin(),vec.end());
    auto maxStu = *vec.begin();
    cout << maxStu.name << ' ' << maxStu.chi << ' ' << maxStu.ma << ' ' << maxStu.en;
    return 0;
}