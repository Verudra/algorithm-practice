#include<bits/stdc++.h>
using namespace std;
stack<int>stk1;
stack<char>stk2;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		int t; scanf("%d",&t);
		stk1.push(t);
	}
	for(int i = 1;i < n;i ++){
		char c; cin >> c;
		stk2.push(c);
	}
	while(stk1.size() > 1){
		char c = stk2.top(); stk2.pop();
		int b = stk1.top(); stk1.pop();
		int a = stk1.top(); stk1.pop();
		if(c == '+') stk1.push(a+b);
		else if(c == '-') stk1.push(a-b);
		else if(c == '*') stk1.push(a*b);
		else{
			if(b == 0){
				printf("ERROR: %d/0",a);
				return 0;
			}
			stk1.push(a/b);	
		}
	}
	
	printf("%d",stk1.top());
	return 0;
} 
