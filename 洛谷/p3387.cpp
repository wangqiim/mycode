#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 10004;
const int maxm = 100005;
struct{
	int t;
	int next;
}edge[maxm],ed[maxm];
int cnt = 1;
int head[maxn],h[maxn];	//h,ed为缩点的链式前向星 
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

int ff[maxn];	//所在强连通分量的父亲
int w[maxn];	//每个点的权值 
stack<int> s;
bool in_stack[maxn];
int dfn[maxn];	//每个点访问到时的时间 
int low[maxn];	//每个点所能到达的最早的时间戳
int time = 1;
int n,m;
int in[maxn];	//每个点的入度 
queue<int> que;	//用来拓扑排序
int dp[maxn];	//每个点为终点的最大路径 

void tarjan(int u){	//当前访问u点 
	s.push(u);
	dfn[u] = low[u] = time++;
	in_stack[u] = true;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v = edge[i].t;
		if(dfn[v]==0){	//还没有被访问过了 
			tarjan(v);
			low[u] = min(low[u],low[v]);//v能到达u之前的时间戳（有回路） 
		}else if(in_stack[v]){	//换句话说，v也能到达u 
			low[u] = min(low[u],low[v]);
		}//剩余的情况是横叉点，忽略 
	}
	if(dfn[u]==low[u]){	//没能够回溯到更早的时间点
        while (1){
        	int y = s.top();
        	s.pop();
            ff[y]=u;
            in_stack[y]=false;
            if (u==y) break;
            w[u]+=w[y];
		}
	}
	return;
}

void suotu(){	//建立缩图
	int cnt2 = 1; 
	for(int u=1;u<=n;u++){
		for(int i=head[u]; i!=0; i=edge[i].next){	//遍历老图 
			int x = ff[u],y = ff[edge[i].t];
			if(x!=y){	//u和v不在一个强连通分量内 
				ed[cnt2].t = y;
				ed[cnt2].next = h[x];
				h[x] = cnt2++;
				in[y]++;	//入度 
			}
		}
	}
	return;
}

int topo(){
	for(int i=1;i<=n;i++)
		if(ff[i]==i&&in[i]==0){
			que.push(i);
			dp[i] = w[i];
		}
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i=h[u]; i!=0; i=ed[i].next){
			int v = ed[i].t;
			dp[v] = max(dp[v],dp[u]+w[v]);
			in[v]--;
			if(in[v]==0) que.push(v);
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++)
		res = max(res,dp[i]);
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i =0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++)
		if(dfn[i]==0)//该点还没被访问过 
			tarjan(i);//得到强连通分量 
	suotu();//得到缩图
	printf("%d",topo());//拓扑求解 
	return 0;
} 
