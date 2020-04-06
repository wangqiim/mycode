#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10004;
const int INF = 0x7fffffff;
struct{
	int t;
	int next;
}edge[maxn*100];
int cnt = 1;
int head[maxn];
int n;	//杂务的数目
int res[maxn];
int len[maxn];

void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return; 
}

int dfs(int now){
	if(res[now] != 0) return res[now];
	else{
		int ans = 0;
		for(int i=head[now];i!=0;i=edge[i].next)
			ans = max(ans,dfs(edge[i].t));
		res[now] = ans + len[now];
		return res[now];
	}
}

int solve(){
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans = max(ans,dfs(i));
	return ans;
}

int main(){
	scanf("%d",&n);
	int no,pre;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&no,&len[i],&pre);
		while(pre!=0){
			addedge(no,pre);
			scanf("%d",&pre);
		}
	}
	printf("%d\n",solve());
	return 0;
} 
