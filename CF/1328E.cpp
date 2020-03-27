#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200005;

struct {
	int t;
	int next;	//���һ���ߵ�nextΪ0 
}edge[maxn*2];
int cnt = 1;
int head[maxn];	 
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int depth[maxn];	//ÿ���������
int fa[maxn][22]; //����2^i������ 
int lg[maxn];	//log[a]=b    b = log2(a)����ȡ��+1  
//���a�����2^b����; lg[1] = 1; lg[2] = 2 ; lg[3] = 2 ; lg[4] = 3;lg[5] = 3;
//lg����������� ���ڵ�a�㣬���ϱ���������2^b��һ�����Ե�����ڵ㡣 

void dfs(int rt,int father){	//rt:��ǰ��㣬father:���׽�� 
	fa[rt][0] = father;
	depth[rt] = depth[father]+1;
	for(int i=1;i <= lg[depth[rt]];i++)
		fa[rt][i] = fa[fa[rt][i-1]][i-1];
		//rt��2^i���ȵ���rt��2^(i-1)���ȵ�2^(i-1)����
	for(int i=head[rt];i!=0;i=edge[i].next)
		if(edge[i].t != father) 
			dfs(edge[i].t,rt);
}

bool check(int x, int y) {	 //x�����Ĭ��x>y 
	if(depth[x] < depth[y])
		swap(x,y);
	while(depth[x] > depth[y]) 
	    x = fa[x][lg[depth[x]-depth[y]] - 1]; //������ͬһ���
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
