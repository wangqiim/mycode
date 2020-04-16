#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5000006;
int nums[maxn];
int n,k;

void quicksort(int l,int r){
	int left = l,right = r;
	int mid = nums[(l+r)/2];
	while(left<=right){
		while(nums[right]>mid)
			right--;
		while(nums[left]<mid)
			left++;
		if(left<=right){
			swap(nums[left],nums[right]);
			right--;
			left++;
		}
	}
	if(k<=right) quicksort(l,right);
	else if(left<=k) quicksort(left,r);
	else return;
	return;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	quicksort(0,n-1);
	printf("%d\n",nums[k]);
	return 0;
}

