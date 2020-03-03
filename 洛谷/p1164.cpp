#include<cstdio>

const int maxn = 1001;
int v[maxn];
int dp[maxn];	
//dp[i][j]:��ǰi�ֲ�Ʒ,���û���jԪ�ķ�����
//dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i]]
//�߽�����:dp[i][0] = 1;

int main(){
	int n,m;//��n�ֲ�,��mԪ
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
