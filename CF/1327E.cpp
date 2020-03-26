#include<cstdio>
#include<cmath>

const int mod = 998244353;
const int maxn = 200005;
long long nums[maxn]={1};	//nums[i] = 10^i; 

int main(){
	int n;
	scanf("%d",&n);
	long long res;
	for(int i = 1;i<=n;i++)
		nums[i] = 10*nums[i-1]%mod;
	for(int i=1;i<=n;i++){
		int mid = n-i-1;
		if(i==n)
			res = 10;
		else{
			res = (18*nums[n-i])%mod;		//分别贴两边 
			res = (res+81*nums[n-i-1]*mid)%mod;		//不贴边
		}
		printf("%d ",res); 
	}
	return 0;
}
