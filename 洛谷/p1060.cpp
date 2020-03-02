#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 30000;
const int maxm = 25;
int v[maxm];	//�۸� 
int w[maxm];	//��Ҫ��
int dp[maxm][maxn]; //dp[i][j]��ʾ����ǰi����Ʒ�۸񲻳���j����������ļ�ֵ�� 
//dp[i][j] = max(dp[i-1][j-price[i]]+price[i]*importance[i],dp[i-1][j])
//��������������һά������������� 
int main(){
	int n,m;	//��Ǯ����ϣ���������Ʒ����
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
