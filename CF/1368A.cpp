#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	int t;
	long long a, b, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &a, &b, &n);
		if (a < b) swap(a, b);
		int ans = 0;
		while (a <= n) {
			b += a;
			swap(a, b);
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
