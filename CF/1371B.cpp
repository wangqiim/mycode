#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int t;
	long long n, r;
	long long ans;
	scanf("%d",&t);
	while (t--) {	
		scanf("%lld%lld", &n, &r);
		if (n == r) {
			ans = (1 + (n - 1)) * (n - 1) / 2 + 1;
		} else if (n > r) {
			ans = (1 + r) * r / 2;
		} else {	//n < r
			ans = (1 + (n - 1)) * (n - 1) / 2 + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
