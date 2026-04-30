#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int sa[N];
int m,n; 
bool pdbig(int p,int val){
	if(p > n) return true;
	if(sa[p] > val) return false;
	return pdbig(p<<1,sa[p]) && pdbig(p<<1|1,sa[p]); 
}
bool pdmin(int p,int val){
	if(p > n) return true;
	if(sa[p] < val) return false;
	return pdmin(p<<1,sa[p]) && pdmin(p<<1|1,sa[p]); 
}
void dfs(int p,vector<int>&v){
	if(p > n) return ;
	dfs(p<<1,v);
	dfs(p<<1|1,v);
	v.push_back(sa[p]);
}
int main(){
	scanf("%d%d",&m,&n);
	while(m --){
		for(int i = 1;i <= n;i ++) scanf("%d",&sa[i]);
		if(pdbig(1,sa[1])) printf("Max Heap\n");
		else if(pdmin(1,sa[1])) printf("Min Heap\n");
		else printf("Not Heap\n");
		vector<int>v;
		dfs(1,v);
		for(int i = 0;i < v.size();i ++){
			printf("%d",v[i]);
			if(i != v.size()-1) printf(" ");
		}	
		printf("\n");
	}
	return 0;
}
