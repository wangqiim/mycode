#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int digit[10];	//从低位到高位存，1个位,2百位 
int dp[10][10];	//前i位中,前一位是j的总数 

int dfs(int len,int pre,bool limit){	//pre如果是-2说明第len位不能为0 
	//len当前位, pre前一位, limit是边界
	if(len == 0)
		if(pre == -2)
			return 0;
		else
			return 1;
	if(!limit&&dp[len][pre]&&pre!=-2) return dp[len][pre];
	int cnt = 0;
	int up_bound = (limit?digit[len]:9);
	for(int i=0;i<=up_bound;i++){
		if(abs(pre-i)<2)
			continue;
		if(pre==-2&&i==0)
			cnt += dfs(len-1,-2,limit&&i==up_bound);
		else
			cnt += dfs(len-1,i,limit&&i==up_bound);
	}
	if(!limit&&pre!=-2)
		dp[len][pre] = cnt;
	return cnt;
} 

int solve(int n){
	int len = 0;
	while(n){
		digit[++len] = n%10;
		n /= 10;
	}
	return dfs(len,-2,true);
}


int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",solve(b)-solve(a-1));
	return 0;
}
