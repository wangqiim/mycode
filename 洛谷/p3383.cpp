#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 1e8+1;
const int maxq = 1e6+1;
bool nums[maxn];	//false 表示是质数 
int prime[maxn];
int cnt=0;
	//使用欧拉筛法：保证每个数n都只被他最小的质因数a*(n/a)筛去一次! 
void find_prime(int n){	//初始化nums[3-n]
	for(int i=2;i<n;i++){
		if(nums[i]==false)
			prime[++cnt] = i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){	//遍历之前的素数 
			nums[prime[j]*i] = true;
			if(i%prime[j] == 0)	break;
			//跳出的原因是,i中已经有a(prime[j])这个质因数了b(prime[j+1)
			//j再往后循环只会再让一个数既被a筛去一次,又被 b筛去一次 
		} 
	}
	return;
}

int main(){
	int n,q,k;	//范围和查询个数 
	scanf("%d %d",&n,&q);
	find_prime(n);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		printf("%d\n",prime[k]);
	}
	return 0;
}

/*	//埃氏筛法超时GG 
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 1e8+1;
const int maxq = 1e6+1;
bool nums[maxn];	//false 表示是质数 
int prime[maxn];
int res[maxq];

void find_prime(int n){	//初始化nums[3-n]
	int cnt=1;
	for(int i=2;i<n;i++){
		if(nums[i]) continue;
		prime[cnt++] = i;
		for(int j=i+i;j<=n;j+=i){
			nums[j] = true;
		} 
	}
	return;
}

int main(){
	int n,q,k;	//范围和查询个数 
	scanf("%d %d",&n,&q);
	find_prime(n);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		res[i]=prime[k];
	}
	for(int i=0;i<q;i++)
		printf("%d\n",res[i]);
	return 0;
}*/
