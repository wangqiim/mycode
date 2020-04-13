#include<cstdio>
#include<vector> 
using namespace std;

const int maxn = 100005;
vector<int> G[maxn];
bool flag;
int res = 0;
int rt;
void dfs(int u, int fa,int cnt){
	if(G[u].size() == 1 && u!=rt)
		if(cnt&1) flag=true;
	int tot = 0;	//该结点直接连叶子的个数 
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if (G[v].size() == 1)
			tot++;
		if(v!=fa)
			dfs(v, u, cnt + 1);
	}
	if(tot>=2)
		res += (tot-1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++){
		int u, v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1;i <= n;i++)
		if (G[i].size() == 1){	//找到一个叶子结点开始遍历 
			rt = i;
			break;
		}
	dfs(rt, 0, 0);
	if(flag) putchar('3');
	else putchar('1');
	printf(" %d\n",n - 1 - res);
	return 0;
}
