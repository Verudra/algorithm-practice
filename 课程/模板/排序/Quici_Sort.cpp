#include <bits/stdc++.h>
using namespace std;
int nums[100005];
void Quick_Sort(int v[],int l,int r){
	if(l >= r) return ;   // 待排序长度小于等于1，到达递归边界
	int val = v[l+r>>1];  // 取基准元素
	int i = l-1, j = r+1; // 双指针处理
	while(i < j){
		do i++; while(v[i] < val); // 找到左侧第一个大于等于val的位置
		do j--; while(v[j] > val); // 找到右侧第一个小于等于val的位置
		if(i < j) swap(v[i],v[j]); // 交换
	}
	Quick_Sort(v,l,j);   // 递归处理左侧
	Quick_Sort(v,j+1,r); // 递归处理右侧
	return ;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%d",&nums[i]);
	Quick_Sort(nums,1,n);
	for(int i = 1;i <= n;i ++) printf("%d ",nums[i]);
	return 0;
}