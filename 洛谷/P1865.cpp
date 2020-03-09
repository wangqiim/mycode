#include<cstdio>

const int maxm = 1000006;
bool nums[maxm];	//是质数则为falses
int prime[maxm];	//第i个质数 
int cnt_pri = 0;
int acc[maxm]={0,0};//acc[i]:1-i的质数个数
int cnt_acc = 2;
//欧拉筛法 
void find_prime(int n){
	for(int i=2;i<=n;i++){
		if(nums[i]==false){	//是质数 
			prime[cnt_pri++] = i;
			acc[cnt_acc] = acc[cnt_acc-1]+1;
		}else
			acc[cnt_acc] = acc[cnt_acc-1];
		cnt_acc++;
		for(int j=0;j<cnt_pri&&i*prime[j]<=n;j++){
			nums[i*prime[j]] = true;
			if(i%prime[j]==0) break;
		}
	}
	return;
}


int main(){
	int n,m;	//询问次数n,范围1-m
	scanf("%d %d",&n,&m);
	find_prime(m);	//欧拉筛 
	int l,r;
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		if(l<1||r>m) printf("Crossing the line\n");
		else printf("%d\n",acc[r]-acc[l-1]);
	}
	return 0;
}
