#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 202;
int dp[maxn][maxn][maxn];
int r[maxn],g[maxn],b[maxn];

bool cmp (int a, int b) {
	return a > b;
}

int main() {
	int R, G, B;
	scanf("%d%d%d", &R, &G, &B);
	for (int i = 0; i < R; i++) scanf("%d",&r[i]);
	for (int i = 0; i < G; i++) scanf("%d",&g[i]);
	for (int i = 0; i < B; i++) scanf("%d",&b[i]);
	sort(r, r + R, cmp);
	sort(g, g + G, cmp);
	sort(b, b + B, cmp);
	for (int i = 0; i <= R; i++) for (int j = 0; j <= G; j++) for (int k = 0; k <= B; k++) {
		if (i&&j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
		if (i&&k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
		if (j&&k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
	}
	//cout << dp[1][0][1] << endl <<  dp[2][0][2] << endl << dp[2][1][3];
	int ans = 0;
	for (int i = 0; i <= R; i++) for (int j = 0; j <= G; j++) for (int k = 0; k <= B; k++) ans = max(ans, dp[i][j][k]);
	printf("%d\n", ans);
	return 0;
}

