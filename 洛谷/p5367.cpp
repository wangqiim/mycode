#include<cstdio>
#define lowbit(x) ((x)&(-x))
const int MOD = 998244353;
const int maxn = 1000006;
int a[maxn];
int c[maxn];	//树状数组 
int nums[maxn] = {1}; //nums[i] = i!

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) nums[i] = (1LL*nums[i-1]*i)%MOD;	//转换成LL防止溢出 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int res = 1;
	for(int i=n;i>=1;i--){
		int sum = 0;
		for(int j=a[i];j>=1;j-=lowbit(j))
			sum += c[j];
		for(int j=a[i];j<=n;j+=lowbit(j))	//更新操作 
			c[j] += 1;
		res = (res+ 1LL*sum*nums[n-i]%MOD)%MOD;	//转化成LL防止溢出 
	}
	printf("%d",res);
	return 0;
}
//PS:我直接用LL哪有这么多麻烦= = 

