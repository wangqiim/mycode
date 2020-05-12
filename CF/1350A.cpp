#include<cstdio>
#include<cmath>

int main(){
	int t;
	scanf("%d",&t);
	long long n,k;
	while(t--){
		scanf("%lld%lld",&n,&k);
		if(n % 2 == 0)
			printf("%lld\n",n+2*k);
		else{
			long long t = n;
			for(int i = 3; i <= sqrt(n); i++){
				if(n % i == 0){
					t = i;
					break;
				}
			}
			n += t;
			printf("%lld\n",n + (k-1)*2);
		}
	}
	return 0;
}
