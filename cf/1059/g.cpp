#include <bits/stdc++.h>
using namespace std;
void work(){
    int n;
    scanf("%d",&n);
    vector<int>vec(n+1);
    if(n <= 5){
        switch(n){
            case 2:
            printf("-1\n");
            break;
            case 3:
            printf("2 3\n3 1\n"); 
            break;
            case 4:
            printf("1 2\n1 3\n1 4\n");
            break;
            case 5:
            printf("5 1\n1 2\n2 3\n3 4\n");
            break;
        }  
    }
    else{
        // push(vec,)
        // init(vec);
        vec[2] = 1;
        vec[3] = 2;
        vec[4] = 3;
        vec[5] = 1;
        for(int i = 6;i <= n;i ++){
            vec[i] = 1;
            vec[i-1] = 2;
        }
        for(int i = 2;i <= n;i ++){
            printf("%d %d\n",i,vec[i]);
        }
    }
    return ;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        work();
    }
    return 0;
}