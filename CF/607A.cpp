#include<cstdio>
#include<algorithm>
using namespace std; 

const int maxn = 1000006;

struct pos_pow{
	bool exist;
	int pow;
};
pos_pow nums[maxn];
int dp[maxn];	//dp[i] ��ʾ0-i�������� 

int main(){
	int n;
	int ans = 0;	//��������ĵ����� 
	scanf("%d",&n);
	int x,y;
	int size = 0;	//���ұߵ�����λ��. 
	for(int i=1;i<=n;i++){	//����n������ 
		scanf("%d %d",&x,&y);
		nums[x].exist = true;
		nums[x].pow = y;
		size = max(size,x);
	}
	if(nums[0].exist){
		dp[0] = 1;	
		ans = 1;
	}
	for(int i=1;i<=size;i++){
		if(nums[i].exist)
			if(nums[i].pow>=i)
				dp[i] = 1;
			else
				dp[i] = 1+dp[i-nums[i].pow-1];
		else
			dp[i] = dp[i-1];
		ans = max(ans,dp[i]);
	}
	printf("%d\n",n-ans);
	return 0;
}
