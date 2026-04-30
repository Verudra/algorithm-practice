#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int sa[N];
void Merge_Sort(int l,int r){
	if(l >= r) return ;
	int mid = (l+r)/2;
	Merge_Sort(l,mid);    // 先递归处理两个分区间
	Merge_Sort(mid+1,r); 
	int i = l,j = mid+1;  // 注意双指针的作用
	vector<int>vec;
	while(i <= mid && j <= r){
		if(sa[i] < sa[j]) vec.push_back(sa[i ++]);
		else vec.push_back(sa[j ++]);
	}
	while(i <= mid) vec.push_back(sa[i++]);
	while(j <= r) vec.push_back(sa[j++]);
	for(int i = 0;i < vec.size();i ++) sa[l+i] = vec[i]; // 别忘了覆盖
	return ;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&sa[i]);
	} 
	Merge_Sort(1,n);
	for(int i = 1;i <= n;i ++){
		printf("%d ",sa[i]);
	}
	return 0;
}