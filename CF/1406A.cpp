#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 102;
int cnt[maxn];

int main() {
	int t, n, a;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i <= 100; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			cnt[a]++;
		}
		int ans1 = -1;
		for (int i = 0; i <= 100; i++) {
			if (cnt[i] != 0)
				ans1 = i;
			else
				break;
		}
		int ans2 = -1;
		for (int i = 0; i <= 100; i++) {
			if (cnt[i] >= 2)
				ans2 = i;
			else
				break;
		}
		printf("%d\n", ans1 + 1 + ans2 + 1);
	}
	return 0;
}
