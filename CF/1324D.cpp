#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200005;
int nums[maxn];	//nums[i] = ai-bi

int main(){
	int n;	//n个老师或学生 
	long long res = 0;
	scanf("%d",&n);
	int b;
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&b);
		nums[i]-=b;
	}
	sort(nums,nums+n);
	for(int i=1;i<n;i++){
		int L = 0,R = i-1;
		int mid;
		while(L<R){	//找到第一个加和大于0的
			mid = (L+R)/2;
			if(nums[mid]+nums[i]>0)
				R = mid;
			else
				L = mid+1;
		}
		if(nums[L]+nums[i]>0) 
			res += i-L;
	}
	printf("%lld",res);
	return 0;
}
