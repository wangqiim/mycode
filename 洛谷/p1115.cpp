#include<cstdio>
#include<algorithm>
using namespace std;

int main(){//��һ 
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
//����:��̬�滮 dp[i]��ʾ��i��β��������������к� 
//dp[i] = max(nums[i],dp[i-1]+nums[i]) �߽�dp[0] = nums[0] 
