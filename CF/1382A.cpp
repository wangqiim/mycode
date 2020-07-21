#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

map<int, bool> exist;

int main() {
	int t;
	scanf("%d", &t);
	int n, m, a, b;
	int ans;
	while (t--) {
		exist.clear();
		scanf("%d%d", &n, &m);
		bool flag = false;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			exist[a] = 1;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d" , &b);
			if (exist.count(b) > 0) {
				flag = true;
				ans = b;
			}
		}
		if (flag) {
			puts("YES");
			printf("1 %d\n", ans);
		} else {
			puts("NO");
		}
	}
	return 0;
}
