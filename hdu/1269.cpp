#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

//���ⲻ������ֱ�Ӽ���һ���м���ǿ��ͨ������Ȼ���ж��Ƿ����1���� 
const int maxn = 10004;
const int maxm = 100005;
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

stack<int> s;
bool in_stack[maxn];
int dfn[maxn];	//ÿ������ʵ�ʱ��ʱ�� 
int low[maxn];	//ÿ�������ܵ���������ʱ���
//ֵΪ0˵����û�б����ʹ� 
int n,m;
int time = 1;
int res = 0;

void init(){
	cnt = 1;	
	for(int i=1;i<=n;i++)
		dfn[i]=low[i]=head[i]=0;
	//��ʼ��ʱ�������ʽǰ���� 
	time = 1;//��ʼ����ʼʱ�� 
	res = 0;
	return;
}

void dfs(int u){	//��ǰ����u�� 
	s.push(u);
	dfn[u]=low[u] = time++;
	in_stack[u] = true;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v = edge[i].t;
		if(dfn[v]==0){	//��û�б����ʹ��� 
			dfs(v);
			low[u] = min(low[u],low[v]);//v�ܵ���u֮ǰ��ʱ������л�·�� 
		}else if(in_stack[v]){	//���仰˵��vҲ�ܵ���u 
			low[u] = min(low[u],low[v]);
		}//ʣ�������Ǻ��㣬���� 
	}
	if(dfn[u]==low[u]){	//û�ܹ����ݵ������ʱ���
		while(s.top()!=u){
			in_stack[s.top()] = false;
			s.pop();
		}
		in_stack[u] = false;
		s.pop();
		res++;
	}
	return;
}

int main(){
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		init();
		int u,v;
		for(int i =0;i<m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for(int i=1;i<=n;i++)
			if(dfn[i]==0)//��û�����ʹ� 
				dfs(i);
		if(res==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
