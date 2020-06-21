#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 502;
const int MAXM = 250002;
int A, B;       // B是点数
int fa[MAXN];       // 并查集的父节点数组

struct Edge {     // 存储边
    int u;
    int v;
    int w;
    bool operator < (Edge b) {
    	return w < b.w;
	}
}edges[MAXM];
int cnt_e = 0;

int find(int x) {
    if (fa[x] != x) 
		fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal() {
    sort(edges, edges + B * B);
    for (int i = 0; i < B; i++ ) fa[i] = i;    // 初始化并查集
    int res = 0;
    for (int i = 0; i < B * B; i++ ) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        u = find(u), v = find(v);
        if (u != v) {     // 如果两个连通块不连通，则将这两个连通块合并
        	//cout << u << "," << v << "," << w << endl;
            fa[u] = v;
            res += w;
        }
    }
    return res;
}

int main() {
	scanf("%d %d",&A, &B);
	//没件商品A元，B件商品 
	int K;
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) {
			scanf("%d",&K);
			if (K > A) K = A;
			edges[cnt_e].u = i;
			edges[cnt_e].v = j;
			if (i == j) 
				edges[cnt_e].w = 0x7fffffff;
			else
				edges[cnt_e].w = (K == 0 ? A : K);
			cnt_e++;
		}
	}
	int ans = kruskal() + A;
	printf("%d\n", ans);
	return 0;
}