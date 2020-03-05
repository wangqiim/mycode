#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10001;
const int maxk = 10001;

int dp[maxn];	//dp[i]:i-nʱ�̵�������ʱ�� 
//���iʱ��û�й���,dp[i] = dp[i+1]+1
//���iʱ���й�����ʼ,dp[i] = max(dp[i],dp[i+ÿһ��i��ʼ����ĳ���ʱ��] 
pair<int,int> nums[maxk];	//first:��ʼ second:����

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;	//���տ�ʼʱ�併������ 
}
 
int main(){
	int n,k;	//n����ʱ��,k������ 
	scanf("%d %d",&n,&k);	
	for(int i=0;i<k;i++)
		scanf("%d %d",&nums[i].first,&nums[i].second);
	sort(nums,nums+k,cmp);
	if(nums[0].first!=n) dp[n]=1;
	for(int i=n-1,j=0;i>=1;i--){
		while(nums[j].first>i&&j!=k-1) j++;
		if(nums[j].first==i){	//��ʱ���й�����ʼ
			for(int z=j;z<k&&nums[z].first==i;z++)
				dp[i] = max(dp[i],dp[i+nums[z].second]);
		}else{
			dp[i] = dp[i+1]+1;
		}
	}
	printf("%d",dp[1]);
	return 0;
}
