#include<cstdio>
#include<algorithm>
using namespace std;

int dp[4][5];
int a[4][5]={{},{0,7,3,3,1},{0,4,8,3,6},{0,7,3,3,3}};

int main(){
	dp[0][1] = 7;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			dp[i][j] = max(dp[i-1][j]&a[i][j],dp[i][j-1]&a[i][j]);
		}
	}
	printf("%d",dp[3][4]);
}
