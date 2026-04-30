#include <bits/stdc++.h>
using namespace std;
struct Stu{
    string name;
    char sex;
    int age;
    double wei;
    Stu(){
        cin >> name >> sex >> age >> wei;
    }
    void out(){
        cout << name << ' ' << sex << ' ' << age << ' ' << fixed << setprecision(1) << wei;
    }
};
int main(){
    Stu stu = Stu();
    stu.out();
    return 0;
}