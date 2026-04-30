#include <bits/stdc++.h>
using namespace std;
bool equ(string s,int p,string ss){
	for(int i = 0;i < ss.length();i ++){
		if(p+i >= s.length()) return false;
		if(s[p+i] != ss[i]) return false;
	}
	return true;
}
string getstring(string s,int l,int r){
	string ss = "";
	for(int i = l;i <= r;i ++) ss += s[i];
	return ss;
}
string rep(string s,int pos,int len,string ss){
	return getstring(s,0,pos-1)+ss+getstring(s,pos+len,s.length());
}
int main(){
	int n;
//	scanf("%d",&n);
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i ++){
		int op; 
//		scanf("%d",&op);
		cin >> op;
		if(op == 1){
			continue;
			string ss;
			cin >> ss;
			int pos = -1;
			for(int j = 0;j < s.length();j ++){
				if(equ(s,j,ss)){
					pos = j;
					break;
				}
			}
//			printf("%d\n",pos-1);
			cout << pos << '\n';
		}
		else if(op == 2){
//			continue;
			string s2,s3; cin >> s2 >> s3;
			for(int j = 0;j < s.length();j ++){
				if(equ(s,j,s2)){
					s = rep(s,j,s2.length(),s3);
					break;
				}
			}
			cout << s << '\n';
		}
		else if(op == 3){
			continue;
			string c1,c2,s4;
			cin >> c1 >> c2 >> s4;
//			cout << c1 << ' ' << c2  << ' ' << s4 << '\n';
			for(int j = 0;j < s.length();j ++){
				if(equ(s,j,c1+c2)){
					s = rep(s,j,2,c1+s4+c2);
					j = j+s4.length();
				}
			}
			cout << s << '\n';
		}
	}
	return 0;
}
