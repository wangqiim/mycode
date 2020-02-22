#include<iostream>
#include<algorithm>
using namespace std;

const int mod = 100000000;
int dp[101][101][11][11]={{{{0}}}};

int main(){	//dp[i][j][m][n]	ʹ��i������,j�����,ĩβ������m��������������n������ķ�����
	//dp[i][j][1][0] = dp[i-1][j][0][1~k]	//��һλ����� 
	//dp[i][j][0][1] = dp[i][j-1][1~k][0]	//��һλ�ǲ��� 
	//dp[i][j][m][0] = dp[i-1][j][m-1][0]	//��һλ�ǲ��� 
	//dp[i][j][0][n] = dp[i][j-1][0][n-1]  //��һλ����� 
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	for(int i=1;i<=n1&&i<=k1;i++)
		dp[i][0][i][0] = 1;
	for(int j=1;j<=n2&&j<=k2;j++)
		dp[0][j][0][j] = 1;
	for(int i=1;i<=n1;i++)
		for(int j=1;j<=n2;j++){
			for(int k=1;k<=min(j,k2);k++)
				dp[i][j][1][0] =(dp[i][j][1][0]+dp[i-1][j][0][k])%mod;
			for(int k=1;k<=min(i,k1);k++)
				dp[i][j][0][1] =(dp[i][j][0][1]+dp[i][j-1][k][0])%mod;
			for(int m=2;m<=min(i,k1);m++)
				dp[i][j][m][0] =(dp[i][j][m][0]+dp[i-1][j][m-1][0])%mod;
			for(int n=2;n<=min(j,k2);n++)
				dp[i][j][0][n] =(dp[i][j][0][n]+dp[i][j-1][0][n-1])%mod;
		}
	int res=0;
	for(int i=1;i<=k1;i++){	//������β 
		res=(res+dp[n1][n2][i][0])%mod;
	}
	for(int j=1;j<=k2;j++){	//�����β 
		res=(res+dp[n1][n2][0][j])%mod;
	}
	cout<<res;
	return 0;
}

/* ֱ���õݹ飬�����ʱ
int n1,n2,k1,k2,n; 
int dfs(int loc,int seq_foot,int seq_horse,int foot_num,int horse_num){	//��ǰλ��,�Ѿ������ĸ���,�Ѿ�ʹ�õĸ��� 
	if(loc==n)
		return 1;
	int res = 0;
	if(foot_num<n1&&seq_foot<k1)	//��λ��Ϊ���� 
		res+=dfs(loc+1,seq_foot+1,0,foot_num+1,horse_num);
	if(horse_num<n2&&seq_horse<k2)	//��λ��Ϊ��� 
		res+=dfs(loc+1,0,seq_horse+1,foot_num,horse_num+1);
	return res;
}

int main(){
	cin>>n1>>n2>>k1>>k2;
	n=n1+n2;
	cout<<dfs(0,0,0,0,0);
	return 0;
}*/


