#include <cstdio>
#include <algorithm>
using namespace std;

const int maxt = 300005;
int dp[maxt];	//ʹ�����ܣ���Ϊʹ�÷����ܵ�ƽ���ٶȱ�һֱ��Ҫ�� 

int main(){
	int M,S,T;	//M��ʼħ��ֵ��S���룬T��ûʱ�� 
	scanf("%d%d%d",&M,&S,&T);
	for(int i=1;i<=T;i++)
		if(M>=10){
			M -= 10;
			dp[i] = dp[i-1]+60;
		}else{
			M += 4;
			dp[i] = dp[i-1];
		}
	for(int i=1;i<=T;i++){
		dp[i] = max(dp[i],dp[i-1]+17);
		if(dp[i]>=S){
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",dp[T]);
	return 0;
} 

