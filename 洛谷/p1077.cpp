#include<cstdio>

using namespace std;
const int maxn=105;
const int MOD = 1000007;
int n, m, a[maxn], dp[maxn][maxn];//前i种花中，消耗了j个的花盆。 
int main(){
	scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    	scanf("%d",&a[i]);
    dp[0][0] = 1;	
    for(int i=1; i<=n; i++)
       for(int j=0; j<=m; j++)
           for(int k=0; k<=j&&k<=a[i]; k++)
              dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
    printf("%d\n",dp[n][m]);
    return 0;
}

/*	//无法AC的代码，不知道错在了哪里 
#include<cstdio>

const int maxn = 102;
const int maxm = 102; 
int a[maxn];
int dp[maxm][maxn];	//dp[i][j]第i盆是第一盆j的数量 
int n,m;
int MOD = 1000007;

int solve(int now,int pre,int cnt){	//pre上一盆的摆放的编号,cnt上一轮的颜色使用的个数
	if(now>m) return 1;
	int res = 0;
	if(cnt != a[pre])
		res += solve(now+1,pre,cnt+1);
	for(int i=pre+1;i<=n;i++){
		if(dp[now][i] == -1)
			dp[now][i] = solve(now+1,i,1);
		res=(res+dp[now][i])%MOD;
	}
	return res;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			dp[i][j] = -1;
	int res = solve(1,0,0);
	printf("%d\n",res);
	return 0;
}*/
