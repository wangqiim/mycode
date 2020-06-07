#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
 
const int maxn = 500005;
const int maxm = 1000006;
 
struct Edge{
	int t;
	int next;
}edge[maxm];
int cnt = 1;
int head[maxn] = {0};
void addedge(int u, int v) {
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
 
int t[maxn];
int vis[maxn];
pair<int, int> tp[maxn];	//first:t权值, second:index点的索引，防止排序后丢失 
 
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &a, &b);
    	addedge(a, b);addedge(b, a);
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
		tp[i].first = t[i];
		tp[i].second = i;
	}
	sort(tp + 1, tp + 1 + n);	//按t排序
	bool ans = true;
	for (int u = 1; u <= n && ans; u++) {
		for (int i = 1; i <= t[u]; i++) //初始化vis 
			vis[i] = 0;
		vis[t[u]] = 1;
		for (int i = head[u]; i != 0 && ans; i = edge[i].next) {	//遍历u的所有相邻点 
			int v = edge[i].t;
			if (t[v] == t[u])	//有冲突点 
				ans = false;
			else
				vis[t[v]] = 1;
		}
		for (int i = 1; i <= t[u]; i++)
			if (vis[i] == false) {
				ans = false;
				break;
			}
	}
	if (ans)
		for (int i = 1; i <= n; i++) 
			printf("%d ", tp[i].second);
	else
		puts("-1");
    return 0;
}