#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

const int maxn = 200005;
int a[maxn];
int b[maxn];
int n, k;

bool check(int val) {
	bool ans = false;
	//检查奇数位
	int cnt, bound;
	if (k % 2 == 1) {	//k为奇数，不能取n - 1
		cnt = k / 2 + 1;
		bound = n - 1;
	} else {
		cnt = k / 2;
		bound = n;
	}
	for (int i = 0; i < bound; i++) {
		if (a[i] > val) continue;
		if (a[i] <= val) {
			cnt--;
			i++;
		}
	}
	if (cnt <= 0) ans = true;
	if (!ans) {	//检查偶数位 
		cnt = k / 2;
		if (k % 2 == 1)	//k为奇数，不能取n - 1
			bound = n - 1;
		else 
			bound = n;
		for (int i = 1; i < bound; i++) {
			if (a[i] > val) continue;
			if (a[i] <= val) {
				cnt--;
				i++;
			}
		}
		if (cnt <= 0) ans = true;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	int le = 0, ri = n - 1;
	while (le < ri) {
		int mi = (le + ri) / 2;
		if (check(b[mi]))
			ri = mi;
		else
			le = mi + 1;
	}
	printf("%d\n", b[le]);
	return 0;
}
