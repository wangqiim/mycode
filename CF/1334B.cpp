#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
long long nums[maxn];

int main(){
	int t,n,x;
	long long acc;
	int res;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		acc = 0LL;
		res = 0;
		for(int i=0;i<n;i++) scanf("%d",&nums[i]);
		sort(nums,nums+n);
		for(int i=n-1;i>=0;i--){
			acc+=nums[i];
			if(1.0*acc/(n-i)<x)
				break;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
} 
