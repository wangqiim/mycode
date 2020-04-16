#include<cstdio>
#include<cmath>

int main(){
	int t,d;
	long long m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&d,&m);
		int len = 1;
		int D = d;
		while(D >>= 1) len++;
		long long res = d-(1<<(len-1))+2;
		for(int i=1;i<len;i++)
			res = res*((1<<i)-(1<<(i-1))+1)%m;
		printf("%lld\n",(res-1+m)%m);
	}
	return 0;
}
