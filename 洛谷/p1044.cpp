#include<cstdio>

const int maxn = 19;
int dp[maxn][maxn];
int n;
//���仯���� 
int dfs(int x,int y){	//����x����δ��ջ��ջ����y����ʱ�������
	if(dp[x][y]) return dp[x][y];	//���仯 
	if(x==0) return 1;
	if(y>0) dp[x][y]+=dfs(x,y-1);
	dp[x][y] += dfs(x-1,y+1);
	return dp[x][y];
}

int main(){
	scanf("%d",&n);
	printf("%d\n",dfs(n,0));
	return 0;
}
