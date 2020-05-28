#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int t; 
	long long x1, y1, x2, y2;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&x1, &y1, &x2, &y2);
		printf("%lld\n", abs(x1 - x2) * abs(y1 - y2) + 1);
	}
	return 0;
}

