#include<cstdio>
#include<algorithm>
using namespace std;

const int maxv = 20000;
const int maxn = 31;

int w[maxn];	//每个物品的体积 
int dp[maxv];
//dp[i][j] 从前i个物品中选择不超过j体积的物品，剩余体积的最小值
//dp[i][j] = min(dp[i-1][j],dp[i-1][j-w[i]]) 
//边界条件dp[0][j] = j; 

int main(){
	int v,n;
	scanf("%d %d",&v,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);	//每个物品的体积 
	}
	for(int j=1;j<=v;j++)
		dp[j] = j;
	for(int i=1;i<=n;i++){
		for(int j=v;j>=1;j--){
			if(j>=w[i])
				dp[j] = min(dp[j],dp[j-w[i]]);
		}
	}
	printf("%d",dp[v]);
	return 0;
}
