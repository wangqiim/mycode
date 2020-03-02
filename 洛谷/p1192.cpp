#include<cstdio>

const int maxn = 100001;
int dp[maxn]={1,1};	

int main(){
	int n,k;	//n级台阶,一步最多上k级
	scanf("%d %d",&n,&k); 
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k&&i-j>=0;j++)
			dp[i] = (dp[i] + dp[i-j])%100003;
	printf("%d",dp[n]);
	return 0;
}
