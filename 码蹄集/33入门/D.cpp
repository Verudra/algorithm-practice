#include <bits/stdc++.h>
using namespace std;
struct Point{
    double x,y;
};
struct Circle{
    Point c;
    double r;
};
double dist(Point a,Point b){
    return hypot(a.x-b.x, a.y-b.y);
}
Circle getcircle(Point a,Point b){
    return {{(a.x+b.x)/2,(a.y+b.y)/2},dist(a,b)};
}
Circle getcircle(Point a,Point b,Point c){
    double abx = b.x-a.x, aby = b.y-a.y;
    double acx = c.x-a.x, acy = c.y-a.y;
    if(abx*acy-aby*acy < 1e-7){
        double dab = dist(a,b), dac = dist(a,c), dbc = dist(b,c);
        if(dab >= dac){
            if(dab >= dbc) return getcircle(a,b);
            else return getcircle(b,c);
        } 
        else{
            if(dbc >= dac) return getcircle(b,c);
            else return getcircle(a,c);
        }
    }
    // double cx = (pow(abx,2),+)
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){

    }
}