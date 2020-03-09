#include<cstdio>
#include<queue>
using namespace std;
#define PII pair<int,int>

const int maxn = 5003;
const int maxm = 1000006;

struct node{
	int v; 
	int w;	//边权 
	int next;
}edge[maxm];
int cnt = 1; 
int head[maxn];
void addedge(int u,int v,int w){
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int res=0;
int n_point = 0;
bool visit[maxn];
int ds[maxn];
int n,m;	//n个结点,m条无向边 

void prime(){
	for(int i=1;i<=n;i++) ds[i]=0x7fffffff;
	ds[1] = 0;
	priority_queue<PII,vector<PII>,greater<PII> > pq;	//first距离,second编号
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		PII tp=pq.top();
		pq.pop();
		int d = tp.first;
		int u = tp.second;
		if(visit[u]) continue;
		visit[u] = true; 
		n_point++;res+=d;
		for(int i=head[u];i!=0;i=edge[i].next){	//遍历所有边,更新ds 
			int v = edge[i].v;
			int w = edge[i].w;
			if(visit[v]==false&&w<ds[v]){
				ds[v] = w;
				pq.push(make_pair(w,v)); 
			}
		}
	} 
	return;
}

int main(){
	scanf("%d %d",&n,&m);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	prime();
	if(n_point==n) printf("%d",res);
	else printf("orz");
	return 0;
}
