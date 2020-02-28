#include<cstdio>
#include<cstdlib>
#include<ctime>

const int maxn = 100000;
int nums[maxn];

void quicksort(int begin,int end){
	int l = begin,r = end,t;
	int mid = nums[(l+r)/2];
	while(l<=r){
		while(nums[l]<mid) l++;
		while(nums[r]>mid) r--;
		if(l<=r){
			t = nums[l];
			nums[l] = nums[r];
			nums[r] = t;
			l++;r--;
		}
	}
	if(l<end)
		quicksort(l,end);
	if(r>begin)
		quicksort(begin,r);
	return ;
}

/*
void quicksort(int begin,int end){	//本轮快排开始和结束索引 
	if(begin>=end) return;
	int left=begin,right = end;
	int mid = (left+right)/2;
	int p = nums[mid];	//基准数选的不好会超时 
	nums[mid] = nums[begin];
	while(left<right){
		while(nums[right]>=p&&left<right)
			right--;
		nums[left] = nums[right];
		while(nums[left]<p&&left<right)
			left++;
		nums[right] = nums[left];
	}
	nums[left] = p;
	quicksort(begin,left-1);
	quicksort(left+1,end);
	return;
}*/

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
		if(i!=n-1)
			printf("%d ",nums[i]);
		else
			printf("%d\n",nums[i]);
	return 0;
}
