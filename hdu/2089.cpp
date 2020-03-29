#include<cstdio>

int digit[10];	//2^64 最多不超过20位 
int dp[10][2];	//dp[i][true]  第i位是6时的情况数

int dfs(int len,bool if6,bool limit){	
	//当前处理第len位,if6当前该位上数字是否是6，limit上界
	if(len==0) return 1;
	if(!limit && dp[len][if6])	//如果没有到达上界，并且当前数位已经统计过（记忆化搜索） 
		return dp[len][if6];
	int cnt = 0;
	int up_bound = (limit?digit[len]:9); 
	//如果上一位是上界，则本位最多是digit[len]（否则0-9都可以，所以赋值为9） 
	for(int i=0;i<=up_bound;i++){	//第len位可以取的数字的范围 
		if((if6 && i==2) || i==4)	//剪枝 
			continue;
		cnt += dfs(len-1,i==6,limit&&i==up_bound);
	}
	if(!limit) //不是上届，才记忆。否则可能被覆盖（实际上对于上届，只要单独跑一遍就行了，因此不用另外记忆） 
		dp[len][if6] = cnt;
	return cnt;
}

int solve(int n){	//返回0-n没有62的个数 
	int k = 0;	//有多少个数位
	while(n){
		digit[++k] = n%10;
		n /= 10;
	}
	return dfs(k,false,true);
}

int main(){
	int n,m;
	while(1){
		scanf("%d %d",&n,&m);
		if(!n&&!m) break;
		printf("%d\n",solve(m)-solve(n-1));
	}
	return 0;
}
