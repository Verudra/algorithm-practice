#include<bits/stdc++.h>
using namespace std;
#define int long long
int fun(char c){
	if(c>='0'&&c<='9')return c-'0';
	else return c-'A'+10;
}
void pd(string s){
	bool vis[4]={0};
	for(int i=0;i<s.size();i++){
		char c=s[i];
		int t=fun(c);
		if(t>1)vis[0]=true;
		if(t>7)vis[1]=true;
		if(t>9)vis[2]=true;
		if(t>15)vis[3]=true;
	}
	for(int i=0;i<=3;i++){
		if(vis[i])cout<<0<<" ";
		else cout<<1<<" ";
	}
	cout<<endl;
}
signed main(){
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
        pd(s);
	}
	// for(int i=1;i<=n;i++)pd(s);
	return 0;
}