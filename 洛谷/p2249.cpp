#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000006;
int nums[maxn];
int n,m;

int query(int x){
	int left = 0, right = n-1;
	int mid;
	while(left<right){
		mid = (left+right)/2;
		if(nums[mid]<x){
			left = mid + 1;
		}else{
			right = mid;
		}
	}
	if(nums[left]==x)
		return left+1;
	else
		return -1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&nums[i]);
	sort(nums,nums+n);
	int x;
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		printf("%d ",query(x));
	}
	return 0;	
}

