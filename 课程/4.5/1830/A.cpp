#include <bits/stdc++.h>
using namespace std;
struct Stu{
    int Chi,Mat,Eng;
    int id,pm;
    Stu(){
        scanf("%d%d%d",&Chi,&Mat,&Eng);
    }
    int getAllScore(){
        return Chi+Mat+Eng;
    }
    int getPx1(){
        return Chi+Mat;
    }
    int getPx2(){
        return max(Chi,Mat);
    }
    bool operator< (Stu& b){
        if(getAllScore() != b.getAllScore())
            return getAllScore() > b.getAllScore();
        if(getPx1() != b.getPx1())
            return getPx1() > b.getPx1();
        return getPx2() > b.getPx2();
    }
};
bool pdEql(Stu& a,Stu& b){
    return a.getAllScore() == b.getAllScore() && a.getPx1() == b.getPx1() && a.getPx2() == b.getPx2();
}
int main(){
    int N;
    scanf("%d",&N);
    vector<Stu>vec;
    for(int i = 1;i <= N;i ++){
        Stu t;t.id = i;
        vec.push_back(t);
    }
    sort(vec.begin(),vec.end());
    int now = 1,la = 1;
    for(int i = 0;i < vec.size();i ++){
        vec[i].pm = la;
        now ++;
        if(i != vec.size()-1 && !pdEql(vec[i],vec[i+1])) la = now;
    }
    sort(vec.begin(),vec.end(),[](Stu a,Stu b){return a.id < b.id;});
    for(auto i : vec) printf("%d\n",i.pm);
    return 0;
}