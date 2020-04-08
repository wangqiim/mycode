#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

//此题不卡常，直接计算一共有几个强连通分量，然后判断是否等于1即可 
const int maxn = 10004;
const int maxm = 100005;
struct{
	int t;
	int next;
}edge[maxm];
int cnt = 1;
int head[maxn];
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

stack<int> s;
bool in_stack[maxn];
int dfn[maxn];	//每个点访问到时的时间 
int low[maxn];	//每个点所能到达的最早的时间戳
//值为0说明还没有被访问过 
int n,m;
int time = 1;
int res = 0;

void init(){
	cnt = 1;	
	for(int i=1;i<=n;i++)
		dfn[i]=low[i]=head[i]=0;
	//初始化时间戳与链式前向星 
	time = 1;//初始化起始时间 
	res = 0;
	return;
}

void dfs(int u){	//当前访问u点 
	s.push(u);
	dfn[u]=low[u] = time++;
	in_stack[u] = true;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v = edge[i].t;
		if(dfn[v]==0){	//还没有被访问过了 
			dfs(v);
			low[u] = min(low[u],low[v]);//v能到达u之前的时间戳（有回路） 
		}else if(in_stack[v]){	//换句话说，v也能到达u 
			low[u] = min(low[u],low[v]);
		}//剩余的情况是横叉点，忽略 
	}
	if(dfn[u]==low[u]){	//没能够回溯到更早的时间点
		while(s.top()!=u){
			in_stack[s.top()] = false;
			s.pop();
		}
		in_stack[u] = false;
		s.pop();
		res++;
	}
	return;
}

int main(){
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		init();
		int u,v;
		for(int i =0;i<m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for(int i=1;i<=n;i++)
			if(dfn[i]==0)//还没被访问过 
				dfs(i);
		if(res==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
