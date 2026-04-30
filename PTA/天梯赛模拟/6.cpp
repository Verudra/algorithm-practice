#include<bits/stdc++.h>
using namespace std;
int sa[10];
int main(){
	for(int i = 1;i <= 9;i ++) scanf("%d",&sa[i]);
	for(int i = 1;i < 9;i ++){
		if(i%2 == 1){
			sa[i+1] += sa[i]/2;
			sa[i]%=2;
		}
		else{
			sa[i+1] += sa[i]/3;
			sa[i] %= 3;
		}
		printf("%d ",sa[i]);
	}
	printf("%d",sa[9]);
	return 0;
}
