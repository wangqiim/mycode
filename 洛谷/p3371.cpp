#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

const int maxn = 100005;	//点数 
const int maxm = 200005;	//边数 

struct node{
	int t;	//目标结点 
	int w;	//边权 
	int next;	//下一个邻点 
}edge[maxm];
int cnt = 1;//当前有cnt-1个边
int head[maxn]={0};	//每个顶点的邻边
void addedge(int u,int v,int w){	//添加边u->v 
	edge[cnt].t = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
} 

bool visit[maxn] = {false};
int ds[maxn];
int n,m,s,t;	//n个点,m条边,s是起点,t是终点 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
//优先级是first距离(小顶堆)	
//first距离,second结点编号1-n.使用结构体也行,需要重载小于号或者比较函数 
int res;

void dijkstra(){
	for(int i=1;i<=n;i++)	ds[i] = 0x7fffffff;	//距离矩阵初始化
	ds[s] = 0;
	pq.push(make_pair(0,s)); 
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int u = p.second;	//当前结点 
		int d = p.first;	//当前结点距离开始结点的距离
		if(visit[u]) continue;
		visit[u]=true;	//更新visit
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			int w = edge[i].w;
			if(visit[v]==false&&d+w<ds[v]){
				ds[v] = d+w;
				pq.push(make_pair(d+w,v));
			}
		} 	
	}
	return;
}

int main(){
	scanf("%d %d %d",&n,&m,&s);
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%d ",ds[i]);
	return 0;
}