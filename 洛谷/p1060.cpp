#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 30000;
const int maxm = 25;
int v[maxm];	//价格 
int w[maxm];	//重要度
int dp[maxm][maxn]; //dp[i][j]表示购买前i件物品价格不超过j的情况下最大的价值。 
//dp[i][j] = max(dp[i-1][j-price[i]]+price[i]*importance[i],dp[i-1][j])
//亦可以逆序遍历开一维，逆序滚动数组 
int main(){
	int n,m;	//总钱数和希望购买的物品个数
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&v[i],&w[i]);
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j>v[i])
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*w[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d",dp[m][n]);
	return 0;
}
