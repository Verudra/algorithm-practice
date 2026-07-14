#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,cnt[N];
int main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 	 	int t;
 		cin>>t;
 		t+=50;
 		cnt[t]++;
	}
	int ans=-1;
	for(int i=0;i<=100;i++)
	{
	 	if(cnt[i]>n/2)
	 		ans=i;
	}
	if(-1) cout<<"no";
	else cout<<ans-50;
	return 0;
}