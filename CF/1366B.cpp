#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int t, n, x, m, l, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &x, &m);
		int le = x, ri = x;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &l, &r);
			if (r < le || l > ri) {
				continue;
			} else {
				le = min(le, l);
				ri = max(ri, r);
			}
		}
		printf("%d\n", ri - le + 1);
	}
	return 0;
} 
