#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500005;
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

void dfs(int &rt,int father){	//rt:��ǰ��㣬father:���׽�� 
	fa[rt][0] = father;
	depth[rt] = depth[father]+1;
	for(int i=1;i <= lg[depth[rt]];i++)
		fa[rt][i] = fa[fa[rt][i-1]][i-1];
		//rt��2^i���ȵ���rt��2^(i-1)���ȵ�2^(i-1)����
	for(int i=head[rt];i!=0;i=edge[i].next)
		if(edge[i].t != father) 
			dfs(edge[i].t,rt);
}

int LCA(int x, int y) {	 
	if(depth[x] < depth[y])
		swap(x,y);
	while(depth[x] > depth[y]) 
	    x = fa[x][lg[depth[x]-depth[y]] - 1]; //������ͬһ���
	if(x == y)
	    return x;
	for(int k = lg[depth[x]] - 1; k >= 0; --k) //����������
	    if(fa[x][k] != fa[y][k])  //��Ϊ����Ҫ��������LCA������һ�㣬�������ǿ϶�����ȣ��������Ⱦ�����ȥ��
	        x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int main(){
	int n,m,s;	//n���㣬n-1���ߣ�ѯ��m�Σ�s����� 
	scanf("%d %d %d",&n,&m,&s);
	int x,y;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	for(int i = 1;i<=n;i++)		//����lg�����ж�һ����������ٲ��� 
		lg[i] = lg[i-1] + ((1<<lg[i-1]) == i);
	int a,b;
	dfs(s,0);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}


