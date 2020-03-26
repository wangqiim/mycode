#include<cstdio>

int main(){
	int t;
	long long n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		if((n&1)==(k&1) && n>=k*k){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
