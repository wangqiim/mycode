#include<cstdio>
#include<algorithm>
using namespace std;
//ʹ�ü��仯����+����ͼ�ķ����� 
//�����������ȹ��������򣬱���Ȼ�����θ������ܵ��ĵ��resҲ�ɣ������Ͳ��÷���ͼ�� 
const int maxn = 100005;
const int maxm = 200005;
struct{
	int t;
	int next;
}edge[maxm];
int cnt = 1;
int head[maxn];
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

int n,m;
int res[maxn];

int dfs(int u){
	if(res[u]!=0) return res[u];
	int ans = 0;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v = edge[i].t;
		ans = max(ans,dfs(v));
	}
	res[u] = ans + 1;
	return res[u];
}

int main(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		addedge(v,u);	//����ͼ 
	}
	for(int i=1;i<=n;i++)
		dfs(i);
	for(int i=1;i<=n;i++)
		printf("%d\n",res[i]);
	return 0;
}
