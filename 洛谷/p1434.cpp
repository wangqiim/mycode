#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 102;
int dp[maxn][maxn];
int nums[maxn][maxn];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int r,c;

int dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx<1||yy<1||xx>r||yy>c||nums[xx][yy]>=nums[x][y])
			continue;
		dp[x][y] = max(dp[x][y],dfs(xx,yy)+1);
	}
	return dp[x][y];
}

int main(){
	int res = 0;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&nums[i][j]);
	for(int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
			res = max(res, dfs(i,j));
	printf("%d\n", res);
	return 0;
}
