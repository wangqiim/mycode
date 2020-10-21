#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 100005;
int posi[maxn];
int neg[maxn];
int a[maxn];


bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t, n;
	long long ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int np = 0, nn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] >= 0) {
				posi[np++] = a[i];
			} else {
				neg[nn++] = a[i];
			}
		}
		ans = 0LL;
		if (n == 5) {
			ans = (1LL) * a[0] * a[1] * a[2] * a[3] * a[4];
			printf("%lld\n", ans);
			continue;
		}
		sort(posi, posi + np, cmp);
		sort(neg, neg + nn);
		ans = 0x8000000000000000LL;
		if (np >= 5) 
			ans = max(ans, (1LL) * posi[0] * posi[1] * posi[2] * posi[3] * posi[4]);
		if (np >= 3 && nn >= 2) 
			ans = max(ans, (1LL) * posi[0] * posi[1] * posi[2] * neg[0] * neg[1]);
		if (np >= 1 && nn >= 4) 
			ans = max(ans, (1LL) * posi[0] * neg[0] * neg[1] * neg[2] * neg[3]);
		if (np == 0)
			ans = max(ans, (1LL) * neg[nn-1] * neg[nn-2] * neg[nn-3] * neg[nn-4] * neg[nn-5]);
		printf("%lld\n", ans);	
	}
	return 0;
}
