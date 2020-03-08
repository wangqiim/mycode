#include<cstdio>
#include<algorithm>
using namespace std;

int main(){//法一 
	int n,x;
	scanf("%d",&n);
	int acc = 0;
	int res = -10001;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		acc+=x;
		res = max(res,acc);
		if(acc<0) acc = 0;
	}
	printf("%d",res);
	return 0;
}
//法二:动态规划 dp[i]表示已i结尾的最大连续子序列和 
//dp[i] = max(nums[i],dp[i-1]+nums[i]) 边界dp[0] = nums[0] 
