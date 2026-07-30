#include<bits/stdc++.h>
using namespace std;
const int N=7891;
struct gay{
	int a;
	string b;
	int c;
}d[N];
bool cmp(gay s1,gay s2){
	if(s1.c!=s2.c) return s1.c<s2.c;
	else return s1.a<s1.a;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].b>>d[i].c;
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<d[i].a<<" "<<d[i].b<<" "<<d[i].c<<"\n";
	}
	return 0;
}
