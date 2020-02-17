#include<cstdio>
using namespace std;

const int maxn = 501;
const int inf = 1000000000;
int n,m,s,des;
int G[maxn][maxn];
int W[maxn][maxn];
int d[maxn];
int weight[maxn];
bool isvis[maxn] = {false};
int pre[maxn];

void dijkstra(int start,int destination){
	for(int i = 0 ;i<n;i++){
		d[i] = inf;
		weight[i] = inf;
		pre[i] == i;
	}
	d[start] = 0;
	weight[start] = 0;
	for(int i = 0;i<n;i++){
		int min = inf,u = -1;
		for(int j = 0;j < n ;j++){
			if(d[j]<min&&isvis[j] == false){
				u = j;
				min = d[j];
			}
		}
		if(u == -1|| u == destination)
			return;
		isvis[u] = true;
		for(int v = 0;v<n;v++){
			if(isvis[v]==false&&G[u][v]>0){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u]+G[u][v];
					weight[v]=W[u][v]+weight[u];
					pre[v] = u;	//更新前驱 
				}else if(d[u]+G[u][v] == d[v]&&W[u][v]+weight[u]<weight[v]){
					weight[v]=W[u][v]+weight[u];
					pre[v] = u;	//更新前驱 
				}
			}
		} 
	}
	return;
}

void dfs(int v){
	if(v == s)
		printf("%d ",v);
	else{
		dfs(pre[v]);
		printf("%d ",v);
	}
    return;
}

int main(){
	scanf("%d %d %d %d",&n,&m,&s,&des);
	int c1,c2,g,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&c1,&c2,&g,&w);
		G[c1][c2] = G[c2][c1] = g;
		W[c1][c2] = W[c2][c1] = w;
	}
	dijkstra(s,des);
	dfs(des);
	printf("%d %d",d[des],weight[des]);
	return 0;
}
