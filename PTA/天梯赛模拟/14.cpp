#include<bits/stdc++.h>
using namespace std;
const int N = 105;
typedef long long ll;
ll sa[N][N];
ll sum[N][N];
int n;
int ans = 0;
const int INF = 0x3f3f3f3f;
ll gsum(int xl,int yl,int xr,int yr){
	return sum[xr][yr]-sum[xl-1][yr]-sum[xr][yl-1]+sum[xl-1][yl-1]; 
}
void fun(int l,int lx,int rx){
	for(int i = 0;i < lx;i ++) 
		sa[rx-i][l] = sa[lx-i][l];
	for(int i = rx-lx;i >= 0;i --)
		sa[i][l] = -INF;
	return ;
}
bool work(){
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sa[i][j];
		}
	}
	int lx,ly,rx,ry;
	ll maxn = -1;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			for(int i2 = i;i2 <= n;i2 ++){
				for(int j2 = j;j2 <= n;j2 ++){
					if(gsum(i,j,i2,j2) > maxn){
						maxn = gsum(i,j,i2,j2);
						lx = i,ly = j,rx = i2,ry = j2;
					}
				}
			}
		}
	}
	if(maxn == -1) return false;
	else{
		printf("(%d, %d) (%d, %d) %d\n",ly,lx,ry,rx,maxn);
//		system("pause");
		ans += maxn;
		for(int i = ly;i <= ry;i ++) fun(i,lx-1,rx);
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			scanf("%lld",&sa[i][j]);
			if(sa[i][j] == 0) sa[i][j] = -INF;
		}
	}
	while(work());
	printf("%d",ans);
	return 0;
}
