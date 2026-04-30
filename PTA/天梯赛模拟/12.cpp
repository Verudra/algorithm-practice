#include <bits/stdc++.h>
using namespace std;
int l,n;
int sumL[5],sumH[5];
int mp[5][5];
int ans;
void dfs(int x,int y){
	if(x == n && y == n){
		if(sumL[y] == sumH[x] && sumL[y] <= l){
			ans ++;
		}
		return ;
	}
	if(x == n){
		if(sumL[y] > l) return ;
		mp[x][y] = l-sumL[y];
		sumL[y] += mp[x][y];
		sumH[x] += mp[x][y];
		dfs(x,y+1);
		sumL[y] -= mp[x][y];
		sumH[x] -= mp[x][y];
		mp[x][y] = 0;
	}
	if(y == n){
		if(sumH[x] > l) return ;
		mp[x][y] = l-sumH[x];
		sumL[y] += mp[x][y];
		sumH[x] += mp[x][y];
		dfs(x+1,1);
		sumL[y] -= mp[x][y];
		sumH[x] -= mp[x][y];
		mp[x][y] = 0;
	}
	if(x != n && y != n){
		for(int i = 0;i <= min(l-sumH[x],l-sumL[y]);i ++){
			mp[x][y] = i;
			sumL[y] += i;
			sumH[x] += i;
			dfs(x,y+1);
			sumL[y] -= i;
			sumH[x] -= i;
			mp[x][y] = 0;
		}	
	}
	return ;
}
int main(){
	scanf("%d%d",&l,&n);
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
