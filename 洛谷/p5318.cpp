#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100005;
vector<int> G[maxn];	//Ð¡¶¥¶Ñ
bool vis_dfs[maxn];
bool vis_bfs[maxn];
stack<int> s;
queue<int> que;
int n,m;


void dfs(int now){
	s.push(now);
	while(!s.empty()){
		int u = s.top();
		s.pop();
		if(vis_dfs[u]) continue;
		vis_dfs[u] = true;
		printf("%d ",u);
		int len = G[u].size();
		for(int i=len-1;i>=0;i--){
			if(!vis_dfs[G[u][i]])
				s.push(G[u][i]);
		}
	}
	putchar('\n');
	return;	
}

void bfs(int now){
	que.push(now);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		if(vis_bfs[u]) continue;
		vis_bfs[u] = true;
		printf("%d ",u);
		int len = G[u].size();
		for(int i=0;i<len;i++){
			if(!vis_bfs[G[u][i]])
				que.push(G[u][i]);
		}
	}
	putchar('\n');
	return;	
}

int main(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	dfs(1);
	bfs(1);
	return 0;
}
