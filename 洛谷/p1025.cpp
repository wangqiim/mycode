//动态规划解法
#include<cstdio>

const int maxn = 201;

int dp[maxn][maxn];	
//dp[i][j]表示把和为i的数放到j个盒子里的方法数 
//dp[i][j] = dp[i-1][j-1] + dp[i-j][j] (有1的+无1的) 
//i>=j 边界dp[i][i] = 1; dp[i][1] = 1; 
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		dp[i][i] = 1;
		dp[i][1] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<i;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
		}
	}
	printf("%d",dp[n][k]);
	return 0;
} 



/*//递归解法 
#include<cstdio>

int n,k;	//把数字n分成k份
int res=0;

void dfs(int now,int sum,int last){	//处理now位时的和sum,当前添加数>=last 
	if(now==k){
		if(sum == n) res++;
		return;
	}
	if(sum == n) return;
	for(int i=last;i<=n-sum;i++){
		dfs(now+1,sum+i,i);
	}
	return;
}

int main(){
	scanf("%d %d",&n,&k);
	dfs(0,0,1);	//通过第三个参数保证递归时序列是非降序的防止重复 
	printf("%d",res);
	return 0; 
}*/
