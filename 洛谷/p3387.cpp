#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 10004;
const int maxm = 100005;
struct{
	int t;
	int next;
}edge[maxm],ed[maxm];
int cnt = 1;
int head[maxn],h[maxn];	//h,edΪ�������ʽǰ���� 
void addedge(int u,int v){
	edge[cnt].t = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	return;
}

int ff[maxn];	//����ǿ��ͨ�����ĸ���
int w[maxn];	//ÿ�����Ȩֵ 
stack<int> s;
bool in_stack[maxn];
int dfn[maxn];	//ÿ������ʵ�ʱ��ʱ�� 
int low[maxn];	//ÿ�������ܵ���������ʱ���
int time = 1;
int n,m;
int in[maxn];	//ÿ�������� 
queue<int> que;	//������������
int dp[maxn];	//ÿ����Ϊ�յ�����·�� 

void tarjan(int u){	//��ǰ����u�� 
	s.push(u);
	dfn[u] = low[u] = time++;
	in_stack[u] = true;
	for(int i=head[u];i!=0;i=edge[i].next){
		int v = edge[i].t;
		if(dfn[v]==0){	//��û�б����ʹ��� 
			tarjan(v);
			low[u] = min(low[u],low[v]);//v�ܵ���u֮ǰ��ʱ������л�·�� 
		}else if(in_stack[v]){	//���仰˵��vҲ�ܵ���u 
			low[u] = min(low[u],low[v]);
		}//ʣ�������Ǻ��㣬���� 
	}
	if(dfn[u]==low[u]){	//û�ܹ����ݵ������ʱ���
        while (1){
        	int y = s.top();
        	s.pop();
            ff[y]=u;
            in_stack[y]=false;
            if (u==y) break;
            w[u]+=w[y];
		}
	}
	return;
}

void suotu(){	//������ͼ
	int cnt2 = 1; 
	for(int u=1;u<=n;u++){
		for(int i=head[u]; i!=0; i=edge[i].next){	//������ͼ 
			int x = ff[u],y = ff[edge[i].t];
			if(x!=y){	//u��v����һ��ǿ��ͨ������ 
				ed[cnt2].t = y;
				ed[cnt2].next = h[x];
				h[x] = cnt2++;
				in[y]++;	//��� 
			}
		}
	}
	return;
}

int topo(){
	for(int i=1;i<=n;i++)
		if(ff[i]==i&&in[i]==0){
			que.push(i);
			dp[i] = w[i];
		}
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i=h[u]; i!=0; i=ed[i].next){
			int v = ed[i].t;
			dp[v] = max(dp[v],dp[u]+w[v]);
			in[v]--;
			if(in[v]==0) que.push(v);
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++)
		res = max(res,dp[i]);
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i =0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++)
		if(dfn[i]==0)//�õ㻹û�����ʹ� 
			tarjan(i);//�õ�ǿ��ͨ���� 
	suotu();//�õ���ͼ
	printf("%d",topo());//������� 
	return 0;
} 
