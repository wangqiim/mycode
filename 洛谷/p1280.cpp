#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10001;
const int maxk = 10001;

int dp[maxn];	//dp[i]:i-n时刻的最大空闲时间 
//如果i时刻没有工作,dp[i] = dp[i+1]+1
//如果i时刻有工作开始,dp[i] = max(dp[i],dp[i+每一个i开始任务的持续时间] 
pair<int,int> nums[maxk];	//first:开始 second:持续

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;	//按照开始时间降序排列 
}
 
int main(){
	int n,k;	//n工作时间,k任务数 
	scanf("%d %d",&n,&k);	
	for(int i=0;i<k;i++)
		scanf("%d %d",&nums[i].first,&nums[i].second);
	sort(nums,nums+k,cmp);
	if(nums[0].first!=n) dp[n]=1;
	for(int i=n-1,j=0;i>=1;i--){
		while(nums[j].first>i&&j!=k-1) j++;
		if(nums[j].first==i){	//该时刻有工作开始
			for(int z=j;z<k&&nums[z].first==i;z++)
				dp[i] = max(dp[i],dp[i+nums[z].second]);
		}else{
			dp[i] = dp[i+1]+1;
		}
	}
	printf("%d",dp[1]);
	return 0;
}
