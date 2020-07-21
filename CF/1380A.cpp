#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 1003;
int p[maxn];
int le[maxn];
int ri[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) ri[i] = le[i] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		int mi, ind;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				mi = p[i];
				ind = i;
			}
			else {
				if (mi < p[i])
					le[i] = ind;
				else {
					mi = p[i];
					ind = i;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			if (i == n) {
				mi = p[i];
				ind = i;
			}
			else {
				if (mi < p[i])
					ri[i] = ind;
				else {
					mi = p[i];
					ind = i;
				}
			}
		}
		bool flag = false;
		for (int i = 1; i <= n; i++)
			if (le[i] && ri[i]) {
				flag = true;
				puts("YES");
				printf("%d %d %d\n", le[i], i, ri[i]);
				break;
			}
		if (!flag) puts("NO");
	}
	return 0;
}
