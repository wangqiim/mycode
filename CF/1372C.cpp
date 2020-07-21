#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 200005;
//int a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<int> a(n + 1, 0);
		int flag = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] != i) {
				if (flag == 0) {
					flag = 1;
					ans++;
				} 
				else  if (a[i - 1] == i - 1) 
						ans = 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

