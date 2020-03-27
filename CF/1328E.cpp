#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200005;

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

void dfs(int rt,int father){	//rt:当前结点，father:父亲结点 
	fa[rt][0] = father;
	depth[rt] = depth[father]+1;
	for(int i=1;i <= lg[depth[rt]];i++)
		fa[rt][i] = fa[fa[rt][i-1]][i-1];
		//rt的2^i祖先等于rt的2^(i-1)祖先的2^(i-1)祖先
	for(int i=head[rt];i!=0;i=edge[i].next)
		if(edge[i].t != father) 
			dfs(edge[i].t,rt);
}

bool check(int x, int y) {	 //x的深度默认x>y 
	if(depth[x] < depth[y])
		swap(x,y);
	while(depth[x] > depth[y]) 
	    x = fa[x][lg[depth[x]-depth[y]] - 1]; //先跳到同一深度
	if(x == y)
	    return true;
	else
		return false;
}

int knums[maxn];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v),addedge(v,u);
	}
	for(int i=1;i<=n;i++)
		lg[i] = lg[i-1] + ((1<<lg[i-1]) == i);
	int a,b;
	dfs(1,0);
	int k;
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		int max_dep=0,max_no=0;
		int t;
		for(int j=0;j<k;j++){
			scanf("%d",&t);
			knums[j] = fa[t][0];
			if(depth[knums[j]]>max_dep){
				max_dep = depth[knums[j]];
				max_no = knums[j];
			}
		}
		bool res = true;
		for(int j=0;j<k;j++){
			if(!check(knums[j],max_no)){
				res = false;
				break;
			}
		}
		if(res)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
	
}
