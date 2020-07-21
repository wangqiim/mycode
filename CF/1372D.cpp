#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 200005;
long long acc[maxn];

int main() {
	int t, n;
	long long a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a);
		if (i == 1 || i == 2) acc[i] = a;
		else acc[i] = acc[i - 2] + a;
	}
	long long ans = 0LL;
	for (int i = 1; i < n; i++)	// i,i+1 Á¬Ðø 
		if (i % 2 == 1)	ans = max(ans, acc[i] + acc[n - 1] - acc[i - 1]);
		else ans = max(ans, acc[i] + acc[n] - acc[i - 1]);
	ans = max(ans, acc[n]);
	printf("%lld", ans);
	return 0;
}
