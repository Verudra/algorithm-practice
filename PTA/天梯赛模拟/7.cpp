#include<bits/stdc++.h>
using namespace std;
struct node{
	int y,m,d,hh,mm,ss,k,scor;
}sa[1005];
int maxn[25],maxpos[25];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(maxn,-1,sizeof(maxn));
	for(int i = 1;i <= n;i ++){
		node now;
		scanf("%d-%d-%d %d:%d:%d",&now.y,&now.m,&now.d,&now.hh,&now.mm,&now.ss);
		
		int k,scor;
		scanf("%d%d",&k,&scor);
		
		now.k = k,now.scor=scor;
		sa[i] = now;
		if(maxn[k] < scor){
			maxn[k] = scor;
			maxpos[k] = i;
		}
	}
	vector<int>vec;
	for(int i = 1;i <= m;i ++){
		if(maxpos[i]) vec.push_back(maxpos[i]);
	}
	sort(vec.begin(),vec.end());
	for(auto i : vec){
		printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",sa[i].y,sa[i].m,sa[i].d,sa[i].hh,sa[i].mm,sa[i].ss,sa[i].k,sa[i].scor);
	}
}
