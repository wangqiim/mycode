#include<iostream>
#include<algorithm>
using namespace std;

const int mod = 100000000;
int dp[101][101][11][11]={{{{0}}}};

int main(){	//dp[i][j][m][n]	使用i个步兵,j个骑兵,末尾是连续m个步兵或者连续n个骑兵的方案数
	//dp[i][j][1][0] = dp[i-1][j][0][1~k]	//上一位是骑兵 
	//dp[i][j][0][1] = dp[i][j-1][1~k][0]	//上一位是步兵 
	//dp[i][j][m][0] = dp[i-1][j][m-1][0]	//上一位是步兵 
	//dp[i][j][0][n] = dp[i][j-1][0][n-1]  //上一位是骑兵 
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
	for(int i=1;i<=k1;i++){	//步兵结尾 
		res=(res+dp[n1][n2][i][0])%mod;
	}
	for(int j=1;j<=k2;j++){	//骑兵结尾 
		res=(res+dp[n1][n2][0][j])%mod;
	}
	cout<<res;
	return 0;
}

/* 直接用递归，结果超时
int n1,n2,k1,k2,n; 
int dfs(int loc,int seq_foot,int seq_horse,int foot_num,int horse_num){	//当前位置,已经连续的个数,已经使用的个数 
	if(loc==n)
		return 1;
	int res = 0;
	if(foot_num<n1&&seq_foot<k1)	//该位置为步兵 
		res+=dfs(loc+1,seq_foot+1,0,foot_num+1,horse_num);
	if(horse_num<n2&&seq_horse<k2)	//该位置为骑兵 
		res+=dfs(loc+1,0,seq_horse+1,foot_num,horse_num+1);
	return res;
}

int main(){
	cin>>n1>>n2>>k1>>k2;
	n=n1+n2;
	cout<<dfs(0,0,0,0,0);
	return 0;
}*/


