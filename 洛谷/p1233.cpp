#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5003;
int dp[maxn];	//最长上升降序列
struct wood{
	int l;
	int w;
}nums[maxn];

bool cmp(wood a, wood b){
	if(a.l != b.l) return a.l>b.l;
	else return a.w>b.w;
}

int main(){
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&nums[i].l,&nums[i].w);
	sort(nums+1,nums+n+1,cmp);
	for(int i=1; i<=n; i++){
		dp[i] = 1;
		for(int j=1; j<i; j++)
			if(nums[i].w > nums[j].w)
				dp[i] = max(dp[i],dp[j]+1);
		res = max(res,dp[i]);
	}
	printf("%d",res);
	return 0;
}
