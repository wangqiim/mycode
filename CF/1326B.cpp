#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long 

int main(){
	int n;
	scanf("%d",&n);
	LL x = 0;
	LL b;
	LL a;
	for(int i=1;i<=n;i++){
		scanf("%lld",&b);
		a = b+x;
		x = max(x,a);
		printf("%lld ",a);
	}
	putchar('\n');
	return 0;
}
