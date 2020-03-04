#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pp;

struct node{
	int t;	//目标结点 
	int w;	//边权
	node(){}
	node(int t,int w):t(t),w(w){}
};

const int maxn = 2501;
const int maxm = 6201;
vector<vector<node> > G(maxn+1);	//使用动态数组实现邻接表 
bool isvis[maxn];	//每个点是否已经经过 
int ds[maxn];	//s点到各个点的距离,-1表示不可达 
int res;
int n,m;	//n个点m条边
int s,t;	//起点和终点 

void dijkstra(){
	for(int i=1;i<=n;i++)
		ds[i] = 0x7fffffff;
	ds[s]=0;
	priority_queue<pp,vector<pp>,greater<pp> > pq;	//小顶堆 
	pq.push(make_pair(0,s));
	pp tp;	//tp.first最近距离,tp.second结点 
	while(!pq.empty()){
		tp = pq.top();
		pq.pop();
		int u = tp.second;	//当前结点 
		int d = tp.first;	//当前结点距离开始结点的距离
		if(u==t){
			res = d;
			return;
		}
		if(isvis[u]) continue;	//该点已经被访问过了
		isvis[u] = true;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].t;	//u->v 有边
			if(isvis[v]==false&&d+G[u][i].w<ds[v]){	//i点尚未访问,并且以u为中介可以使得到i点的距离更小
				ds[v] = d+G[u][i].w;
				pq.push(pp(ds[v],v));
			}
		}
	}
}

int main(){
	cin>>n>>m>>s>>t;
	int x,y,z;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		G[x].push_back(node(y,z));
		G[y].push_back(node(x,z));
	}
	dijkstra();
	cout<<res;
	return 0;
	
}



/*
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 2501;
const int maxm = 6201;

int G[maxn][maxn];	//0表示不通 
bool isvis[maxn];	//每个点是否已经经过 
int ds[maxn];	//s点到各个点的距离,-1表示不可达 
int res;
int n,m;	//n个点m条边
int s,t;	//起点和终点 

void dijkstra(){
	for(int i=1;i<=n;i++)
		ds[i] = 0x7fffffff;
	ds[s] = 0;//ds初始化
	for(int k=0;k<n;k++){	//循环k次 
		int next=-1;	//下一个要扩散的结点
		int ds_next = 0x7fffffff; 
		for(int i=1;i<=n;i++){				//优化点1 
			if(isvis[i]==false&&ds[i]<ds_next){
				next = i;
				ds_next = ds[i];
			}
		}
		if(next==-1) return ;//此时此连通图内所有点都已经访问过了 
		isvis[next]=true;//走到next,标记已访问 
		if(next==t){	//如果是终点可以直接返回 
			res = ds_next;
			return;
		}
		for(int i=1;i<=n;i++){//刷新ds		//优化点2 
			if(G[next][i]!=0&&isvis[i]==false)	//i点没有走过
				ds[i]=min(ds[i],ds_next+G[next][i]);
		}
	}
}

int main(){
	scanf("%d %d %d %d",&n,&m,&s,&t);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		scanf("%d",&G[x][y]);
		G[y][x]=G[x][y];
	}
	dijkstra();
	printf("%d",res);
	return 0;
} */

