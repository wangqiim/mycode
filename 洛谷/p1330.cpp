#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10001;
vector<vector<int> > G(maxn);	//�ڽӱ�
int v,e;
int color[maxn];
int sum[3]={0,0,0};

bool dfs(int now,int c){	//now��ǰ�����Ľ��,c��ǰ�����Ҫ����ɫ 
	if(color[now]!=0){
		if(color[now] == c) return true;
		else return false;
	}
	color[now] = c;	//Ⱦɫ
	sum[c]++;
	c=(c==1?2:1);
	int size = G[now].size();
	for(int i=0;i<size;i++){
		if(!dfs(G[now][i],c))
			return false;
	}
	return true;
}

int main(){
	scanf("%d %d",&v,&e);
	int s,d;
	int res=0;
	for(int i=0;i<e;i++){
		scanf("%d %d",&s,&d);
		G[s].push_back(d);
		G[d].push_back(s);
	} 
	for(int i=1;i<=v;i++){
		if(color[i]!=0) continue;	//����ͨ��ͼ�Ѿ����ʹ� 
		if(!dfs(i,1)){
			printf("Impossible");
			return 0;
		}
		res+=min(sum[1],sum[2]);
		sum[1] = 0;sum[2] = 0;
	}
	printf("%d",res);
	return 0;
}


/*//ʹ���ڽӾ���ᱬ�ڴ�,ʹ��vector�����ڽӱ������ʽǰ���� 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10001;
int G[maxn][maxn];
int v,e;//�����,����
int color[maxn];	//0��ʾδȾɫ,Ⱦ��1����2 
int sum[3]={0,0,0};

bool dfs(int now,int c){	//now��ǰ�����Ľ��,c��ǰ�����Ҫ����ɫ 
	if(color[now]!=0){
		if(color[now] == c) return true;
		else return false;
	}
	color[now] = c;	//Ⱦɫ
	sum[c]++;
	c=(c==1?2:1);
	for(int i=1;i<=v;i++){
		if(G[now][i]==1){
			G[i][now] = 0;
			if(!dfs(i,c))
				return false;
		}
	}
	return true;
}

int main(){
	scanf("%d %d",&v,&e);
	int s,d;
	int res=0;
	for(int i=0;i<e;i++){
		scanf("%d %d",&s,&d);
		G[s][d] = 1;G[d][s] = 1;
	} 
	for(int i=1;i<=v;i++){
		if(color[i]!=0) continue;	//����ͨ��ͼ�Ѿ����ʹ� 
		if(!dfs(i,1)){
			printf("Impossible");
			return 0;
		}
		res+=min(sum[1],sum[2]);
		sum[1] = 0;sum[2] = 0;
	}
	printf("%d",res);
	return 0;
}*/
