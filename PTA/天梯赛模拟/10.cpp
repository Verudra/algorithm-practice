#include<bits/stdc++.h>
using namespace std;
map<string,char>mp;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		string id; char c;
		cin >> id >> c;
		mp[id] = c;
	}
	int m; scanf("%d",&m);
	vector<int>vec;
	for(int i = 1;i <= m;i ++){
		int k;
		scanf("%d",&k);
		bool flag = false;
		for(int j = 1;j <= k;j ++){
			string s;
			cin >> s;
			if(mp[s] == 'e') flag = true;
		}
		if(flag == false) vec.push_back(i);
	}
	if(vec.empty()) printf("None");
	else{
		for(int i = 0;i < vec.size();i ++){
			printf("%d",vec[i]);
			if(i != vec.size()-1) printf(" ");
		}
	}
	return 0;
}
