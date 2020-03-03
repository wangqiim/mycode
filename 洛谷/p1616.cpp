#include<cstdio>
#include<algorithm>
using namespace std;

const int maxt = 100001;
const int maxm = 10001;

int tnums[maxm];
int vnums[maxm];
int dp[maxt];

int main(){
	int t,m;//总时间,草药数目
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&tnums[i],&vnums[i]);
	} 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=t;j++)
			if(tnums[i]<=j)
				dp[j] = max(dp[j],dp[j-tnums[i]]+vnums[i]);
	printf("%d",dp[t]);
	return 0;		
}
