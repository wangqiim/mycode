#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn =200;
int dp[maxn][maxn];
int dp2[maxn][maxn];
int nums[maxn];
int acc[maxn];
//dp[i][j]表示合并i-j区域内的石头的最少花费 
//dp[i][j] =  dp[i][k]+dp[k][j]+d(i,j) d(i,j) = acc[j]-acc[i-1]

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
		if(i==0)
			acc[i] = nums[i];
		else
			acc[i] =acc[i-1]+nums[i];
	}
	for(int i=n;i<2*n;i++){	//在nums数组后面再拼接一个nums数组 
		nums[i] = nums[i-n];
		acc[i] = acc[i-1]+nums[i];
	} 
	
	for(int j=1;j<=n-1;j++){	//dp[i][i+j]
		for(int i=0;i+j<=2*n-1;i++){
			dp[i][i+j] = 0x7fffffff;
			int d = (i==0?acc[i+j]:acc[i+j]-acc[i-1]);
			for(int k = i;k<i+j;k++){
				dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+d);
				dp2[i][i+j] = max(dp2[i][i+j],dp2[i][k]+dp2[k+1][i+j]+d);
			}
		}
	}
	int res_min=0x7fffffff,res_max=0;
	for(int i=0;i<n;i++){
		res_min = min(res_min,dp[i][i+n-1]);
		res_max = max(res_max,dp2[i][i+n-1]);
	}
	printf("%d\n%d",res_min,res_max);
	return 0;
}


/*	//非环时 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn =200;
int dp[maxn][maxn];
int dp2[maxn][maxn];
int nums[maxn];
int acc[maxn];
//dp[i][j]表示合并i-j区域内的石头的最少花费 
//dp[i][j] =  dp[i][k]+dp[k][j]+d(i,j) d(i,j) = acc[j]-acc[i-1]

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
		if(i==0)
			acc[i] = nums[i];
		else
			acc[i] =acc[i-1]+nums[i];
	}
	for(int j=1;j<=n-1;j++){	//dp[i][i+j]
		for(int i=0;i+j<=n-1;i++){
			dp[i][i+j] = 0x7fffffff;
			int d = (i==0?acc[i+j]:acc[i+j]-acc[i-1]);
			for(int k = i;k<i+j;k++){
				dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+d);
				dp2[i][i+j] = max(dp2[i][i+j],dp2[i][k]+dp2[k+1][i+j]+d);
			}
		}
	}
	printf("%d\n",dp[0][n-1]);
	printf("%d\n",dp2[0][n-1]);
	return 0;
}*/
