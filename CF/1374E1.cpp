#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;


const int maxn = 200005;
int com[maxn], ali[maxn], bob[maxn];
int acc_com[maxn], acc_ali[maxn], acc_bob[maxn];

int main() {
	int n, k, t, a, b;
	scanf("%d%d", &n, &k);
	int nc = 0, na = 0, nb = 0;
	acc_com[0] = acc_ali[0] = acc_bob[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &t, &a, &b);
		if (a == 1 && b == 1) com[nc++] = t;
		else if (a == 1) ali[na++] = t;
		else if (b == 1) bob[nb++] = t;
	}
	sort(com, com + nc); sort(ali, ali + na); sort(bob, bob + nb);
	for (int i = 1; i <= nc; i++) acc_com[i] = acc_com[i - 1] + com[i - 1];
	for (int i = 1; i <= na; i++) acc_ali[i] = acc_ali[i - 1] + ali[i - 1];
	for (int i = 1; i <= nb; i++) acc_bob[i] = acc_bob[i - 1] + bob[i - 1];
	if (nc + na < k || nc + nb < k) {
		puts("-1");
		return 0;
	}
	int ans = 0x7fffffff;
	for (int i = 0 ; i <= nc && i <= k; i++) {
		if (k - i > na || k - i > nb) continue;
		ans = min(ans, acc_com[i] + acc_ali[k - i] + acc_bob[k - i]);
	}
	printf("%d\n", ans);
	return 0;
} 
