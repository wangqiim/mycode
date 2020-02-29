#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10001;
int nums[maxn]={};

int main(){	//看了题解中用优先队列priority_queue似乎更好 
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	sort(nums,nums+n);
	for(int i=0;i<n-1;i++){	//只有一堆的话不消耗体力
		nums[i] += nums[i+1];
		res+=nums[i];
		int j=i+1;
		for(;j<n-1;j++)//需要重新排序,直接一轮插入排序
			if(nums[j+1]<nums[i])
				nums[j] = nums[j+1];
			else break;
		nums[j] = nums[i];
	}
	printf("%d",res);
	return 0;
}
