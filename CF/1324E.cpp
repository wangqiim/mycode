#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 2003;
int a[maxn];
int dp[maxn][maxn];	//dp[i][j]��i��˯��,��jʱ��˯������˯������
int main(){
	int n,h,l,r;
	int res = 0;
	scanf("%d %d %d %d",&n,&h,&l,&r);
	for(int i=0; i<=n; i++)
		for(int j=0; j<h; j++)
			dp[i][j] = -1;	//��dp[i][j]ʱ�򲻻᲻������˯�� 
	dp[0][0] = 0;	//�߽����� 
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<h;j++){
			if(dp[i][j] == -1) continue;
			if(l<=(j+a[i+1])%h && (j+a[i+1])%h<=r){
				dp[i+1][(j+a[i+1])%h]   = max(dp[i+1][(j+a[i+1])%h]  ,dp[i][j] + 1);
			}else{
				dp[i+1][(j+a[i+1])%h]   = max(dp[i+1][(j+a[i+1])%h]  ,dp[i][j]);
			}
			if(l<=(j+a[i+1]-1)%h && (j+a[i+1]-1)%h<=r){
				dp[i+1][(j+a[i+1]-1)%h] = max(dp[i+1][(j+a[i+1]-1)%h],dp[i][j] + 1);
			}
			else{
				dp[i+1][(j+a[i+1]-1)%h] = max(dp[i+1][(j+a[i+1]-1)%h],dp[i][j]);
			}
		}
	}
	for(int j=0;j<h;j++)
		res = max(res,dp[n][j]);
	printf("%d",res);
	return 0;
}
