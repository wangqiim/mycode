#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500005;
struct {
	int t;
	int next;	//最后一条边的next为0 
}edge[maxn*2];
int cnt = 1;
int head[maxn];	 
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int depth[maxn];	//每个结点的深度
int fa[maxn][22]; //结点的2^i级祖先 
int lg[maxn];	//log[a]=b    b = log2(a)向下取整+1  
//深度a的最大2^b祖先; lg[1] = 1; lg[2] = 2 ; lg[3] = 2 ; lg[4] = 3;lg[5] = 3;
//lg数组的作用是 对于第a层，向上倍减（增）2^b，一定可以到达根节点。 

void dfs(int &rt,int father){	//rt:当前结点，father:父亲结点 
	fa[rt][0] = father;
	depth[rt] = depth[father]+1;
	for(int i=1;i <= lg[depth[rt]];i++)
		fa[rt][i] = fa[fa[rt][i-1]][i-1];
		//rt的2^i祖先等于rt的2^(i-1)祖先的2^(i-1)祖先
	for(int i=head[rt];i!=0;i=edge[i].next)
		if(edge[i].t != father) 
			dfs(edge[i].t,rt);
}

int LCA(int x, int y) {	 
	if(depth[x] < depth[y])
		swap(x,y);
	while(depth[x] > depth[y]) 
	    x = fa[x][lg[depth[x]-depth[y]] - 1]; //先跳到同一深度
	if(x == y)
	    return x;
	for(int k = lg[depth[x]] - 1; k >= 0; --k) //不断向上跳
	    if(fa[x][k] != fa[y][k])  //因为我们要跳到它们LCA的下面一层，所以它们肯定不相等，如果不相等就跳过去。
	        x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int main(){
	int n,m,s;	//n个点，n-1条边，询问m次，s根标号 
	scanf("%d %d %d",&n,&m,&s);
	int x,y;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	for(int i = 1;i<=n;i++)		//更新lg加速判断一次最多跳多少步。 
		lg[i] = lg[i-1] + ((1<<lg[i-1]) == i);
	int a,b;
	dfs(s,0);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}


