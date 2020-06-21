#include<cstdio>

const int maxn = 200005;
char s[maxn];


int main() {
	int t, n, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		scanf("%s", &s);
		int cnt = 0;	
		int empty = 0;
		for (int i = 0 ; i < n; i++) {
			if (s[i] == '1') {
				cnt += (empty - k) / (k + 1);
				empty = 0;
			} else {
				empty++;
				if (i == 0)
					empty += k;
				if (i == n - 1)
					empty += k;
			}
		}
		cnt += (empty - k) / (k + 1);
		printf("%d\n", cnt);
	}
	return 0;
}
