#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 55;
int w[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	int ans;
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; i++) 
			scanf("%d", &w[i]);
		sort(w, w + n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int sum = w[i] + w[j];
				int cnt = 1;
				int le = i + 1, ri = j - 1;
				while (le < ri) {
					if (w[le] + w[ri] == sum) {
						le++;
						ri--;
						cnt++;
					} else if (w[le] + w[ri] > sum) {
						ri--;
					} else {
						le++;
					}
				}
				ans = max(ans, cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
