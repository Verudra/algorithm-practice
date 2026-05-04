#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
double a,b,c,d;
double f(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
int main(){
    cin >> a >> b >> c >> d;
    for(int i = -100;i < 100;i ++){
        double l = i-0.01,r = i+0.99;
        auto pd = [&](double mid){
            if(f(l)*f(mid) < 0) return true;
            return false;
        };
        if(f(l)*f(r) > 0) continue;
        // cout << "!";
        while(r-l > eps){
            double mid = (l+r)/2;
            if(pd(mid)) r = mid;
            else l = mid;
        }
        printf("%.2lf ",l);
    }
    return 0;
}