#include<cstdio>

const int MOD = 80112002;
const int maxn = 5003;
const int maxm = 500005;
struct{
	int t;
	int next;
}edge[maxm];
int cnt=1;
int head[maxn];
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

int in[maxn]={0};
int n,m;
long long dp[maxn];	//以i为最高级，有多少条食物链。

int dfs(int u){
	if(dp[u]) return dp[u];
	dp[u] = 0;
	for(int i=head[u];i;i=edge[i].next){
		int v = edge[i].t;
		dp[u] = (dp[u] + dfs(v))%MOD;
	}
	dp[u] = (dp[u]?dp[u]:1); 
	return dp[u];
} 

int main(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&v,&u);
		addedge(u,v);
		in[v]++;
	}
	long long ans = 0;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			ans = (ans + dfs(i))%MOD;
	printf("%lld\n",ans);
	return 0;
}
