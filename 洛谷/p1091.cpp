#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100;
int nums[maxn];
int dpl[maxn];	//dpl[i]从左到右以nums[i]结尾的最长递增序列的长度 
int dpr[maxn];	//dpr[i]从右到左以nums[i]结尾的最长递增序列的长度 

int main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	for(int i=0;i<n;i++)
		dpl[i]=dpr[i]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(nums[i]>nums[j])
				dpl[i] = max(dpl[i],dpl[j]+1);
	for(int i=n-1;i>=0;i--)
		for(int j=n-1;j>i;j--)
			if(nums[i]>nums[j])
				dpr[i] = max(dpr[i],dpr[j]+1);
	for(int i=0;i<n;i++)
		res = max(res,dpl[i]+dpr[i]);
	res = n-(res-1);
	printf("%d",res);
	return 0;
} 
