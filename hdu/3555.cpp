#include<cstdio>

int digit[20];	//2^64 ��಻����20λ 
long long dp[20][2];	//dp[i][true]  ��iλ��4ʱ�������

long long dfs(int len,bool if4,bool limit){	
	//��ǰ�����lenλ,if4��ǰ��λ�������Ƿ���4��limit�Ͻ�
	if(len==0) return 1LL;
	if(!limit && dp[len][if4])	//���û�е����Ͻ磬���ҵ�ǰ��λ�Ѿ�ͳ�ƹ������仯������ 
		return dp[len][if4];
	long long cnt = 0;
	long long up_bound = (limit?digit[len]:9); 
	//�����һλ���Ͻ磬��λ�����digit[len]������0-9�����ԣ����Ը�ֵΪ9�� 
	for(int i=0;i<=up_bound;i++){	//��lenλ����ȡ�����ֵķ�Χ 
		if(if4 && i==9)	//��֦ 
			continue;
		cnt += dfs(len-1,i==4,limit&&i==up_bound);
	}
	if(!limit) //�����Ͻ죬�ż��䡣������ܱ����ǣ�ʵ���϶����Ͻ죬ֻҪ������һ������ˣ���˲���������䣩 
		dp[len][if4] = cnt;
	return cnt;
}

long long solve(long long n){	//����0-nû��49�ĸ��� 
	int k = 0;	//�ж��ٸ���λ
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
		printf("%lld\n",num+1-solve(num));//��Ϊ��0Ҳ�����û��49������ 
	}
	return 0;
}
