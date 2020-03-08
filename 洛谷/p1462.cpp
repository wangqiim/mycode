#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

/*我又被long long 卡了一个小时 啊啊啊啊啊！*/
const int maxn = 10004;
const int maxm = 100005;
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
int spend[maxn];//每个点的花费 
int nums[maxn];	//排序的spend用于二分遍历 
int n,m,b;	//n:点数,m:边数,b:血量 

long long ds[maxn];
bool visit[maxn]={false};
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
bool check(int top){ //每个点的花费不得超过top
	int s=1,t=n;
	if(spend[s]>top||spend[t]>top) return false;
	for(int i=1;i<=n;i++){	//多次调用，需要初始化 
		ds[i] = 0x7fffffffffffffffll;
		visit[i] = false;
	}
	ds[s] = 0;
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int u = p.second;	//当前结点 
		long long d = p.first;	//当前结点距离开始结点的距离
		//if(d>b) return false;	//1.体力消耗过度GG 
		//if(u==t){
		//	return true;	//2.可以到达返回true; 
			//res = d;	
			//break;	
		//}
		if(visit[u]) continue;
		visit[u]=true;	//更新visit
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			if(spend[v]>top) continue;	//3.过滤掉>top的顶点 
			int w = edge[i].w;
			if(visit[v]==false&&d+w<ds[v]){
				ds[v] = d+w;
				pq.push(make_pair(d+w,v));
			}
		} 	
	}
	return ds[n]<b;
}

int main(){
	scanf("%d %d %d",&n,&m,&b);
	for(int i=0;i<n;i++){	//输入每个点的收费
		scanf("%d",&nums[i]);
		spend[i+1] = nums[i];
	}
	int u,v,w;
	for(int i=0;i<m;i++){	//每条边消耗的体力值 
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w); 
	}
	sort(nums,nums+n);	//按点权排序方便后面进行二分
	if(check(nums[n-1])==false){
		printf("AFK\n");
		return 0;
	}
	int l=0,r=n-1,mid;
	while(l<r){	//开始二分 
		mid=l+(r-l)/2;
		if(check(nums[mid]))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n",nums[l]);
	return 0;
}
/*	//不用long long 则修改一下dijkstra函数跳出条件 
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 10004;
const int maxm = 100005;
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
int spend[maxn];//每个点的花费 
int nums[maxn];	//排序的spend用于二分遍历 
int n,m,b;	//n:点数,m:边数,b:血量 

int ds[maxn];
bool visit[maxn]={false};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
bool check(int top){ //每个点的花费不得超过top
	int s=1,t=n;
	if(spend[s]>top||spend[t]>top) return false;
	for(int i=1;i<=n;i++){	//多次调用，需要初始化 
		ds[i] = 0x7fffffff;
		visit[i] = false;
	}
	ds[s] = 0;
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int u = p.second;	//当前结点 
		int d = p.first;	//当前结点距离开始结点的距离
		if(d>b) return false;	//1.体力消耗过度GG 
		if(u==t) return true;	//2.可以到达返回true; 
		if(visit[u]) continue;
		visit[u]=true;	//更新visit
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			if(spend[v]>top) continue;	//3.过滤掉>top的顶点 
			int w = edge[i].w;
			if(visit[v]==false&&d+w<ds[v]){
				ds[v] = d+w;
				pq.push(make_pair(d+w,v));
			}
		} 	
	}
	return ds[n]<b;
}

int main(){
	scanf("%d %d %d",&n,&m,&b);
	for(int i=0;i<n;i++){	//输入每个点的收费
		scanf("%d",&nums[i]);
		spend[i+1] = nums[i];
	}
	int u,v,w;
	for(int i=0;i<m;i++){	//每条边消耗的体力值 
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w); 
	}
	sort(nums,nums+n);	//按点权排序方便后面进行二分
	if(check(nums[n-1])==false){
		printf("AFK\n");
		return 0;
	}
	int l=0,r=n-1,mid;
	while(l<r){	//开始二分 
		mid=l+(r-l)/2;
		if(check(nums[mid]))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n",nums[l]);
	return 0;
}
*/
