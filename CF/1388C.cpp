#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int maxn = 100005;
int p[maxn];	// p[1] 生活在1城市的人的数量  累计和的m 
int h[maxn];

bool vis[maxn];
vector<int> G[maxn];

//1是首都 

int d[maxn];

void bfs() { 	//广搜从1最远的开始
	int ind = 1;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()) {
		int u = q.front();
		d[ind++] = u;	//存起来 
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			if (vis[G[u][i]] == false) {
				q.push(G[u][i]);
				vis[G[u][i]] = true;
			}
		}
	}
}

int main() {
	int t;
	int n, m;	//n个节点，m个人 
	int u, v;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &h[i]);
		}
		for (int i = 1; i <= n; i++) {	//初始化 
		 	G[i].clear();
		 	vis[i] = false;
		}
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(); 
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		bool flag = true;
		for (int i = n; i >= 1 && flag == true; i--) {
			int u = d[i];
			int sumH = 0;
			vis[u] = true;	//访问过
			int temp = p[u];
			for (int j = 0; j < G[u].size(); j++) { 
				int v = G[u][j];
				if(vis[v] == true) {	//找比u深的点，即已经访问过 
					p[u] += p[v];	//计算经过u点的个数 
					sumH += h[v];
				}
			}
			if (h[u] + temp < sumH || abs(p[u]) < abs(h[u]) || abs(h[u]) % 2 != abs(p[u]) % 2)
				flag = false;
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
