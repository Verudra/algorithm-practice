#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int>&v1,vector<int>&v2,int l1,int r1,int l2,int r2,int now){
	int rval = v1[r1];
//	printf("rval:%d now:%d\n",rval,now);
//	printf("l1:%d r1:%d l2:%d r2:%d\n",l1,r1,l2,r2);
	if(rval % now != 0) return false;
	if(l1 >= r1) return true;
	int mid;
	for(int i = l2;i <= r2;i ++){
		if(rval == v2[i]){
			mid = i;
			break;
		}
	}
	int Llen = mid-l2;
	return dfs(v1,v2,l1,l1+Llen-1,l2,l2+Llen-1,now+1)&&dfs(v1,v2,l1+Llen,r1-1,mid+1,r2,now+1);
}
void work(){
	int n; scanf("%d",&n);
	vector<int>v1,v2;
	for(int i = 1;i <= n;i ++){
		int t; scanf("%d",&t);
		v1.push_back(t);
	}
	for(int i = 1;i <= n;i ++){
		int t; scanf("%d",&t);
		v2.push_back(t);
	}
	if(dfs(v1,v2,0,v1.size()-1,0,v2.size()-1,1)) printf("1\n");
	else printf("0\n");
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
