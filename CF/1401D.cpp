#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100005;
const int maxm = 60004;
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
long long p[maxm];
int vis[maxn];
vector<int> g[maxn];
int t, n, m;
int u, v;
long long edge[maxn];
int cnt = 0;


bool cmp(long long a, long long b) {
	return a > b;
}

//返回子树的大小 
int dfs(int rt) {
	int sum = 1;
	vis[rt] = 1;
	int sz = g[rt].size();
	for (int i = 0; i < sz; i++) {
		if (vis[g[rt][i]] == 0) {
			long long tmp = dfs(g[rt][i]);
			sum = (sum + tmp);
			edge[cnt++] = tmp * (n - tmp);
		}
	}
	return sum;
}

int main() {
	scanf("%d", &t);
	int T = t;
	while (t--) {
		long long ans = 0;
		scanf("%d", &n);
		int ne = n - 1;
		//init
		cnt = 0;
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			g[i].clear();
		}
		for (int i = 0; i < ne; i++) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%lld", &p[i]);
		}
		dfs(1);
	
		if (m <= ne) {	//p比边e少 
			sort(p, p + m, cmp);
			sort(edge, edge + ne, cmp);
			for (int i = 0; i < m; i++) {
				ans = (ans + p[i] * edge[i] % MOD) % MOD;
			}
			for (int i = m; i < ne; i++) {
				ans = (ans + edge[i]) % MOD;
			}
		} else {	//p比边e多 
			sort(p, p + m);
			sort(edge, edge + ne);
			for (int i = ne; i < m; i++) {
				p[ne - 1] = (p[ne - 1] * p[i]) % MOD;
			}
			for (int i = 0; i < ne; i++) {
				edge[i] %= MOD;
				ans = (ans + edge[i] * p[i]) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
