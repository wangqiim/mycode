#include<cstdio>
#define lowbit(x) ((x)&(-x))
const int MOD = 998244353;
const int maxn = 1000006;
int a[maxn];
int c[maxn];	//��״���� 
int nums[maxn] = {1}; //nums[i] = i!

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) nums[i] = (1LL*nums[i-1]*i)%MOD;	//ת����LL��ֹ��� 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int res = 1;
	for(int i=n;i>=1;i--){
		int sum = 0;
		for(int j=a[i];j>=1;j-=lowbit(j))
			sum += c[j];
		for(int j=a[i];j<=n;j+=lowbit(j))	//���²��� 
			c[j] += 1;
		res = (res+ 1LL*sum*nums[n-i]%MOD)%MOD;	//ת����LL��ֹ��� 
	}
	printf("%d",res);
	return 0;
}
//PS:��ֱ����LL������ô���鷳= = 

