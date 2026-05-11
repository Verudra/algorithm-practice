#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
struct Point{
    double x,y;
};
struct Circle{
    Point c;double r;
};
double dist(Point a,Point b){
    return hypot(a.x-b.x,a.y-b.y);
}
Circle getCircle(Point a,Point b){
    return {{(a.x+b.x)/2,(a.y+b.y)/2},dist(a,b)/2};
}
Circle getCircle(Point a,Point b,Point c){
    double bx = b.x-a.x, by = b.y-a.y;
    double cx = c.x-a.x, cy = c.y-a.y;
    double d = 2*(bx*cy-by*cx);
    double blen = bx*bx+by*by;
    double clen = cx*cx+cy*cy;
    double ox = (cy*blen-by*clen)/d;
    double oy = (bx*clen-cx*blen)/d;
    Point ct = {a.x+ox, a.y+oy};
    return {ct, hypot(ox,oy)};
}
int main(){
    int n;
    cin >> n;
    vector<Point>P(n);
    for(int i = 0;i < n;i ++){
        cin >> P[i].x >> P[i].y;
    }
    mt19937 rng(19980731);
    shuffle(P.begin(),P.end(),rng);
    Circle c = {P[0],0};
    for(int i = 1;i < n;i ++){
        if(dist(P[i],c.c) > c.r+EPS){
            c={P[i],0};
            for(int j = 0;j < i;j ++){
                if(dist(P[j],c.c) > c.r+EPS){
                    c = getCircle(P[i],P[j]);
                    for(int k = 0;k < j;k ++){
                        if(dist(P[k],c.c) > c.r+EPS){
                            c = getCircle(P[i],P[j],P[k]);
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10) << c.r << "\n";
    cout << fixed << setprecision(10) << c.c.x << " " << c.c.y << "\n";
    return 0;
}