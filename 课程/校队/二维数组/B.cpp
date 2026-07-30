#include<bits/stdc++.h>
using namespace std;
int main() {
	string s1,m="",mi=string(100,'a'),a;
	getline(cin,s1);
	s1+=" ";
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=','&&s1[i]!=' ') a+=s1[i];
		else{
            if(a.size() == 0) continue;
			if(m.size()<a.size()) m=a;
			if(mi.size()>a.size()) mi=a;
			a="";
		}
	}
    string::npos;
	cout<<m<<endl;
	cout<<mi;

    string mis = string(100,'a');
}