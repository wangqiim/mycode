#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pp;

struct node{
	int t;	//Ŀ���� 
	int w;	//��Ȩ
	node(){}
	node(int t,int w):t(t),w(w){}
};

const int maxn = 2501;
const int maxm = 6201;
vector<vector<node> > G(maxn+1);	//ʹ�ö�̬����ʵ���ڽӱ� 
bool isvis[maxn];	//ÿ�����Ƿ��Ѿ����� 
int ds[maxn];	//s�㵽������ľ���,-1��ʾ���ɴ� 
int res;
int n,m;	//n����m����
int s,t;	//�����յ� 

void dijkstra(){
	for(int i=1;i<=n;i++)
		ds[i] = 0x7fffffff;
	ds[s]=0;
	priority_queue<pp,vector<pp>,greater<pp> > pq;	//С���� 
	pq.push(make_pair(0,s));
	pp tp;	//tp.first�������,tp.second��� 
	while(!pq.empty()){
		tp = pq.top();
		pq.pop();
		int u = tp.second;	//��ǰ��� 
		int d = tp.first;	//��ǰ�����뿪ʼ���ľ���
		if(u==t){
			res = d;
			return;
		}
		if(isvis[u]) continue;	//�õ��Ѿ������ʹ���
		isvis[u] = true;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].t;	//u->v �б�
			if(isvis[v]==false&&d+G[u][i].w<ds[v]){	//i����δ����,������uΪ�н����ʹ�õ�i��ľ����С
				ds[v] = d+G[u][i].w;
				pq.push(pp(ds[v],v));
			}
		}
	}
}

int main(){
	cin>>n>>m>>s>>t;
	int x,y,z;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		G[x].push_back(node(y,z));
		G[y].push_back(node(x,z));
	}
	dijkstra();
	cout<<res;
	return 0;
	
}



/*
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 2501;
const int maxm = 6201;

int G[maxn][maxn];	//0��ʾ��ͨ 
bool isvis[maxn];	//ÿ�����Ƿ��Ѿ����� 
int ds[maxn];	//s�㵽������ľ���,-1��ʾ���ɴ� 
int res;
int n,m;	//n����m����
int s,t;	//�����յ� 

void dijkstra(){
	for(int i=1;i<=n;i++)
		ds[i] = 0x7fffffff;
	ds[s] = 0;//ds��ʼ��
	for(int k=0;k<n;k++){	//ѭ��k�� 
		int next=-1;	//��һ��Ҫ��ɢ�Ľ��
		int ds_next = 0x7fffffff; 
		for(int i=1;i<=n;i++){				//�Ż���1 
			if(isvis[i]==false&&ds[i]<ds_next){
				next = i;
				ds_next = ds[i];
			}
		}
		if(next==-1) return ;//��ʱ����ͨͼ�����е㶼�Ѿ����ʹ��� 
		isvis[next]=true;//�ߵ�next,����ѷ��� 
		if(next==t){	//������յ����ֱ�ӷ��� 
			res = ds_next;
			return;
		}
		for(int i=1;i<=n;i++){//ˢ��ds		//�Ż���2 
			if(G[next][i]!=0&&isvis[i]==false)	//i��û���߹�
				ds[i]=min(ds[i],ds_next+G[next][i]);
		}
	}
}

int main(){
	scanf("%d %d %d %d",&n,&m,&s,&t);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		scanf("%d",&G[x][y]);
		G[y][x]=G[x][y];
	}
	dijkstra();
	printf("%d",res);
	return 0;
} */

