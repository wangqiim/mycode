#include<cstdio>

int main() {
	int t, n, a, cnt_odd, cnt_even;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt_odd = 0;
		cnt_even = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (i % 2 != a % 2) {
				if (a % 2 == 1)
					cnt_odd++;
				else
					cnt_even++;
			}
		}
		int ans;
		if (cnt_odd != cnt_even)
			ans = -1;
		else
			ans = cnt_odd;
		printf("%d\n", ans);
	}
	return 0;
}
