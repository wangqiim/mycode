#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000006;
long long acc[maxn];

int main(){
	int n,k;
	long long a;
	scanf("%d%d",&n,&k);
	acc[0] = 0;
	for(int i=1;i<n;i++){
		scanf("%lld",&a);
		acc[i] = acc[i-1]+a;
	}
	long long res = 0;
	if(k==0){
		res = acc[n-1];
	}else if(k>=n-1){
		res = 0;
	}else{
		for(int i=k;i<n;i++)
			res = max(res,acc[i]-acc[i-k]);
		res = acc[n-1]-res;
	}
	printf("%lld",res);
	return 0;
}
