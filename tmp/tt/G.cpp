#include<bits/stdc++.h>
using namespace std;
int a[5010],s;
int main() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n-2;i++) {
		for (int j=2;j<=n-1;j++) {
				int k=j+1;
				if(k==0){
					cout<<s;
					return 0;
				}
			    if(a[i]+a[j]>k*2){
			        s++;
			}
		}
	}
	cout<<s;
	return 0;
}