#include<cstdio>

const int maxn = 500005;
int nums[maxn];
int temp[maxn];	//归并临时空间 
int n;
long long res=0;

void merge(int left,int mid,int right){	//归并[left~mid]和[mid+1~right] 
	int i=mid,j=right,k=right;
	while(i>=left&&j>=mid+1){
		if(nums[i]>nums[j]){
			res+=j-(mid+1)+1;
			temp[k--] = nums[i--];
		}else{
			temp[k--] = nums[j--];
		}
	}
	while(i>=left) temp[k--] = nums[i--];
	while(j>=mid+1) temp[k--] = nums[j--];
	for(i=left;i<=right;i++)
		nums[i] = temp[i];
	return;
}

void mergesort(int l,int r){	//[l~r]升序排列 
	if(l>=r) return;
	int mid = (l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,r);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	mergesort(0,n-1);
	printf("%lld",res);
	return 0;
}
