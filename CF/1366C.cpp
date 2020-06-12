#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 31;
int cnt_0[maxn * 2]; //(0,0) -> (29,29)
int cnt_1[maxn * 2];

int main() {
	int t, n, m, a;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n + m - 1; i++) {
			cnt_0[i] = 0;
			cnt_1[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a);
				if (a == 0) {
					cnt_0[i + j]++;
				} else {
					cnt_1[i + j]++;
				}
			}
		}
		int ans = 0;
		int bound = n + m - 2;
		for (int i = 0; i <= bound; i++) {
			if (bound % 2 == 0 && i == bound / 2) break;
			if (bound % 2 == 1 && i == (bound + 1) / 2) break;
			ans += min(cnt_0[i] + cnt_0[bound - i], cnt_1[i] + cnt_1[bound - i]);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
