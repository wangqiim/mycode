//��̬�滮�ⷨ
#include<cstdio>

const int maxn = 201;

int dp[maxn][maxn];	
//dp[i][j]��ʾ�Ѻ�Ϊi�����ŵ�j��������ķ����� 
//dp[i][j] = dp[i-1][j-1] + dp[i-j][j] (��1��+��1��) 
//i>=j �߽�dp[i][i] = 1; dp[i][1] = 1; 
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



/*//�ݹ�ⷨ 
#include<cstdio>

int n,k;	//������n�ֳ�k��
int res=0;

void dfs(int now,int sum,int last){	//����nowλʱ�ĺ�sum,��ǰ�����>=last 
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
	dfs(0,0,1);	//ͨ��������������֤�ݹ�ʱ�����Ƿǽ���ķ�ֹ�ظ� 
	printf("%d",res);
	return 0; 
}*/
