#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1003;
int dp[maxn][maxn];
int nums[maxn][maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			scanf("%d",&nums[i][j]);
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + nums[i][j];
		}
	int res = 0;
	for(int j=1;j<=n;j++)
		res = max(res,dp[n][j]);
	printf("%d\n",res);
	return 0;
}
