#include<cstdio>

int digit[10];	//2^64 ��಻����20λ 
int dp[10][2];	//dp[i][true]  ��iλ��6ʱ�������

int dfs(int len,bool if6,bool limit){	
	//��ǰ�����lenλ,if6��ǰ��λ�������Ƿ���6��limit�Ͻ�
	if(len==0) return 1;
	if(!limit && dp[len][if6])	//���û�е����Ͻ磬���ҵ�ǰ��λ�Ѿ�ͳ�ƹ������仯������ 
		return dp[len][if6];
	int cnt = 0;
	int up_bound = (limit?digit[len]:9); 
	//�����һλ���Ͻ磬��λ�����digit[len]������0-9�����ԣ����Ը�ֵΪ9�� 
	for(int i=0;i<=up_bound;i++){	//��lenλ����ȡ�����ֵķ�Χ 
		if((if6 && i==2) || i==4)	//��֦ 
			continue;
		cnt += dfs(len-1,i==6,limit&&i==up_bound);
	}
	if(!limit) //�����Ͻ죬�ż��䡣������ܱ����ǣ�ʵ���϶����Ͻ죬ֻҪ������һ������ˣ���˲���������䣩 
		dp[len][if6] = cnt;
	return cnt;
}

int solve(int n){	//����0-nû��62�ĸ��� 
	int k = 0;	//�ж��ٸ���λ
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
