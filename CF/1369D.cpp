#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

const long long MOD = 1000000007;
const int maxn = 2000006;
long long dp[maxn][2] = {{0,0},{0,0},{0,0},{0,1}};
int t, n;

void solve() {
	for (int i = 4; i <= 2000000; i++) {
		dp[i][1] = (dp[i-1][0] + 2*dp[i-2][0] + 1) % MOD;
		dp[i][0] = (max(dp[i-1][0],dp[i-1][1]) + 2*max(dp[i-2][0],dp[i-2][1])) % MOD;
	}
}

int main() {
	scanf("%d", &t);
	solve();
	while (t--) {
		scanf("%d", &n);
		long long ans = 4 * max(dp[n][0] ,dp[n][1]);
		printf("%lld\n", ans % MOD);
	}
	return 0;
}
