#include<bits/stdc++.h>
using namespace std;
int main(){
	int y,n;
	scanf("%d%d",&y,&n);
	int by = y;
	while(1){
		map<int,bool>mp;
		int ty = y, cnt = 0;
		stack<int>stk;
		while(ty){
			stk.push(ty%10);
			if(mp[ty%10] == false)
				mp[ty%10] = true,cnt ++;
			ty /= 10;
		}
		stack<int>stk2;
		for(int i = 1;i <= 4-stk.size();i ++){
			stk2.push(0);
			if(i == 1 && mp[0] == false) cnt ++;
		}
		if(cnt == n){
			printf("%d ",y-by);
			
			for(int i = 1;i <= 4-stk.size();i ++){
				printf("0");
			}
			while(!stk.empty()){
				printf("%d",stk.top());
				stk.pop();
			}
			break;
		}
		y ++;
	}
	return 0;
}
