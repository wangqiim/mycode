#include<cstdio>

int digit[20];	//2^64 最多不超过20位 
long long dp[20][2];	//dp[i][true]  第i位是4时的情况数

long long dfs(int len,bool if4,bool limit){	
	//当前处理第len位,if4当前该位上数字是否是4，limit上界
	if(len==0) return 1LL;
	if(!limit && dp[len][if4])	//如果没有到达上界，并且当前数位已经统计过（记忆化搜索） 
		return dp[len][if4];
	long long cnt = 0;
	long long up_bound = (limit?digit[len]:9); 
	//如果上一位是上界，则本位最多是digit[len]（否则0-9都可以，所以赋值为9） 
	for(int i=0;i<=up_bound;i++){	//第len位可以取的数字的范围 
		if(if4 && i==9)	//剪枝 
			continue;
		cnt += dfs(len-1,i==4,limit&&i==up_bound);
	}
	if(!limit) //不是上届，才记忆。否则可能被覆盖（实际上对于上届，只要单独跑一遍就行了，因此不用另外记忆） 
		dp[len][if4] = cnt;
	return cnt;
}

long long solve(long long n){	//返回0-n没有49的个数 
	int k = 0;	//有多少个数位
	while(n){
		digit[++k] = n%10;
		n /= 10;
	}
	return dfs(k,false,true);
}

int main(){
	int T;
	scanf("%d",&T);
	long long num;
	while(T--){
		scanf("%lld",&num);
		printf("%lld\n",num+1-solve(num));//因为把0也算成了没有49的数字 
	}
	return 0;
}
