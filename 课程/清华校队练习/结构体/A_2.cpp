#include <bits/stdc++.h>
using namespace std;
struct Student // 结构体名称为 "Student"
{
    string name;   // 姓名
    char sex;      // 性别
    int age;       // 年龄
    double weight; // 体重
};
Student stu;
int main()
{
    cin >> stu.name >> stu.sex >> stu.age >> stu.weight;
    // 保留一位小数
    // 写法一
    cout << stu.name << ' ' << stu.sex << ' ' << stu.age << ' ' << fixed << setprecision(1) << stu.weight;
    // 写法二
    printf("%s %c %d %.1lf", stu.name.c_str(), stu.sex, stu.age, stu.weight);
    return 0;
}