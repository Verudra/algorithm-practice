#include <bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    int days[] = {0,
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };
    int fir = 3; // 2025年的一月一号是周三
    for(int i = 1;i < m;i ++){
        fir = fir+days[i];
    }
    fir = fir%7;
    if(fir == 0) fir = 7;
    cout << "MON TUE WED THU FRI SAT SUN" << endl;
    for(int i = 1;i < fir;i ++) cout << "   " << ' ';
    for(int i = 1;i <= days[m];i ++){
        cout << setw(3) << i;
        if(fir == 7 || i == days[m]){
            cout << endl;
            fir = 1;
        }
        else{
            cout << ' ';
            fir ++;
        }
    }
    return 0;
}