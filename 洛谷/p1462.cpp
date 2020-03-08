#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

/*���ֱ�long long ����һ��Сʱ ������������*/
const int maxn = 10004;
const int maxm = 100005;
struct node{
	int t;	//Ŀ���� 
	int w;	//��Ȩ 
	int next;	//��һ���ڵ� 
}edge[maxm];
int cnt = 1;//��ǰ��cnt-1����
int head[maxn]={0};	//ÿ��������ڱ�
void addedge(int u,int v,int w){	//��ӱ�u->v 
	edge[cnt].t = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
int spend[maxn];//ÿ����Ļ��� 
int nums[maxn];	//�����spend���ڶ��ֱ��� 
int n,m,b;	//n:����,m:����,b:Ѫ�� 

long long ds[maxn];
bool visit[maxn]={false};
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
bool check(int top){ //ÿ����Ļ��Ѳ��ó���top
	int s=1,t=n;
	if(spend[s]>top||spend[t]>top) return false;
	for(int i=1;i<=n;i++){	//��ε��ã���Ҫ��ʼ�� 
		ds[i] = 0x7fffffffffffffffll;
		visit[i] = false;
	}
	ds[s] = 0;
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int u = p.second;	//��ǰ��� 
		long long d = p.first;	//��ǰ�����뿪ʼ���ľ���
		//if(d>b) return false;	//1.�������Ĺ���GG 
		//if(u==t){
		//	return true;	//2.���Ե��ﷵ��true; 
			//res = d;	
			//break;	
		//}
		if(visit[u]) continue;
		visit[u]=true;	//����visit
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			if(spend[v]>top) continue;	//3.���˵�>top�Ķ��� 
			int w = edge[i].w;
			if(visit[v]==false&&d+w<ds[v]){
				ds[v] = d+w;
				pq.push(make_pair(d+w,v));
			}
		} 	
	}
	return ds[n]<b;
}

int main(){
	scanf("%d %d %d",&n,&m,&b);
	for(int i=0;i<n;i++){	//����ÿ������շ�
		scanf("%d",&nums[i]);
		spend[i+1] = nums[i];
	}
	int u,v,w;
	for(int i=0;i<m;i++){	//ÿ�������ĵ�����ֵ 
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w); 
	}
	sort(nums,nums+n);	//����Ȩ���򷽱������ж���
	if(check(nums[n-1])==false){
		printf("AFK\n");
		return 0;
	}
	int l=0,r=n-1,mid;
	while(l<r){	//��ʼ���� 
		mid=l+(r-l)/2;
		if(check(nums[mid]))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n",nums[l]);
	return 0;
}
/*	//����long long ���޸�һ��dijkstra������������ 
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 10004;
const int maxm = 100005;
struct node{
	int t;	//Ŀ���� 
	int w;	//��Ȩ 
	int next;	//��һ���ڵ� 
}edge[maxm];
int cnt = 1;//��ǰ��cnt-1����
int head[maxn]={0};	//ÿ��������ڱ�
void addedge(int u,int v,int w){	//��ӱ�u->v 
	edge[cnt].t = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
int spend[maxn];//ÿ����Ļ��� 
int nums[maxn];	//�����spend���ڶ��ֱ��� 
int n,m,b;	//n:����,m:����,b:Ѫ�� 

int ds[maxn];
bool visit[maxn]={false};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
bool check(int top){ //ÿ����Ļ��Ѳ��ó���top
	int s=1,t=n;
	if(spend[s]>top||spend[t]>top) return false;
	for(int i=1;i<=n;i++){	//��ε��ã���Ҫ��ʼ�� 
		ds[i] = 0x7fffffff;
		visit[i] = false;
	}
	ds[s] = 0;
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int u = p.second;	//��ǰ��� 
		int d = p.first;	//��ǰ�����뿪ʼ���ľ���
		if(d>b) return false;	//1.�������Ĺ���GG 
		if(u==t) return true;	//2.���Ե��ﷵ��true; 
		if(visit[u]) continue;
		visit[u]=true;	//����visit
		for(int i=head[u];i!=0;i=edge[i].next){
			int v = edge[i].t;
			if(spend[v]>top) continue;	//3.���˵�>top�Ķ��� 
			int w = edge[i].w;
			if(visit[v]==false&&d+w<ds[v]){
				ds[v] = d+w;
				pq.push(make_pair(d+w,v));
			}
		} 	
	}
	return ds[n]<b;
}

int main(){
	scanf("%d %d %d",&n,&m,&b);
	for(int i=0;i<n;i++){	//����ÿ������շ�
		scanf("%d",&nums[i]);
		spend[i+1] = nums[i];
	}
	int u,v,w;
	for(int i=0;i<m;i++){	//ÿ�������ĵ�����ֵ 
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w); 
	}
	sort(nums,nums+n);	//����Ȩ���򷽱������ж���
	if(check(nums[n-1])==false){
		printf("AFK\n");
		return 0;
	}
	int l=0,r=n-1,mid;
	while(l<r){	//��ʼ���� 
		mid=l+(r-l)/2;
		if(check(nums[mid]))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n",nums[l]);
	return 0;
}
*/
