#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 100005;
struct{
	int t;
	int next;
}edge[maxn];
int cnt = 1;
int head[maxn];

bool vis[maxn];
int res[maxn];

queue<int> que;

void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

void solve(int n){
	for(int i=n;i>=1;i--){
		if(vis[i]) continue;
		que.push(i);
		while(!que.empty()){
			int u = que.front();
			que.pop();
			if(vis[u]) continue;
			vis[u] = true;
			res[u] = i;
			for(int j=head[u];j!=0;j=edge[j].next){
				int v = edge[j].t;
				if(!vis[v])
					que.push(v);
			}
		}
	}
	return;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		addedge(v,u);	//·´Ïò½¨±ß 
	}
	solve(n);
	for(int i=1;i<=n;i++)
		printf("%d ",res[i]);
	return 0;
}
