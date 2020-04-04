#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))

const int maxn = 200005;
struct{
	int t;
	int next;
}edge[2*maxn]; 
int cnt = 1;
int head[maxn];
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
int n,m,k;	//n个顶点,m条边,k个特殊点

int ds[maxn];
bool vis[maxn];
int a[maxn];	//k个特殊点 
priority_queue<PII,vector<PII>,greater<PII> > pq;
//小顶堆,first:距离,second:结点标号

void dijkstra(int rt){
	while(!pq.empty()) pq.pop(); 
	for(int i=1;i<=n;i++){
		ds[i] = 0x7ffffff;	//ds初始化
		vis[i] = false;
	}
	ds[rt] = 0;
	pq.push(MP(0,rt));
	while(!pq.empty()){
		PII tp = pq.top();
		pq.pop();
		int d = tp.first;
		int u = tp.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			if(!vis[v] && d+1<ds[v]){
				pq.push(MP(d+1,v));
				ds[v] = d+1;
			}
		}
	}
	return;
}

bool cmp(PII a,PII b){
	return a.first-a.second < b.first-b.second;
}

int main(){ 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
		scanf("%d",&a[i]);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	dijkstra(1);
	int res = ds[n];
	vector<PII> nums(k);	//first:起点距离.second:终点距离
	for(int i=0;i<k;i++)
		nums[i].first = ds[a[i]];
	dijkstra(n);
	for(int i=0;i<k;i++)
		nums[i].second = ds[a[i]];
	sort(nums.begin(),nums.end(),cmp);	
	//min(ax+by+1,bx+ay+1)为了始终取前面这项，所以先排序，再扫描一遍O(n)就行了
	//否则需要O(N^2) 
	int xx = 0;	//到起点的距离（每一个点都尝试更新） 
	int ans = 0;
	for(int i=0;i<k;i++){
		if(i!=0){	//该点到终点的距离 
			ans = max(ans,xx+1+nums[i].second);
		}
		xx = max(xx,nums[i].first);
	}
	printf("%d\n",min(res,ans));
	return 0;
}
