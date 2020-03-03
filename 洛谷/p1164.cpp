#include<cstdio>

const int maxn = 1001;
int v[maxn];
int dp[maxn];	
//dp[i][j]:买前i种菜品,正好花费j元的方案数
//dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i]]
//边界条件:dp[i][0] = 1;

int main(){
	int n,m;//有n种菜,有m元
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j>=v[i])
				dp[j] = dp[j] + dp[j-v[i]];
			else 
				dp[j] = dp[j];
		}
	}
	printf("%d",dp[m]);
	return 0;
}
