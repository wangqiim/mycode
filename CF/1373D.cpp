#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;


const int maxn = 200005;
int a[maxn];
int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i % 2 == 0) sum += a[i];
		}
		if (n == 1) {
			printf("%d\n", a[0]);
			continue;
		}
		long long mi = 0;
		long long acc = 0;
		long long ans1 = 0;
		for (int i = 1; i < n; i += 2) {	//处理偶数位置 
			acc += a[i] - a[i - 1];
			ans1 = max(ans1, acc - mi);
			mi = min(mi, acc);
		}
		long long mx = a[0];
		acc = a[0];
		long long ans2 = 0;
		for (int i = 2; i < n; i += 2) {
			acc += a[i] - a[i - 1];
			ans2 = min(ans2, acc - mx);
			mx = max(mx, acc);
		}
		long long res = max(abs(ans1), abs(ans2));
		sum += res;
		printf("%lld\n", sum);
	}
	return 0;
}
