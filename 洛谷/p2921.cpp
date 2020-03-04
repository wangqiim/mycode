#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100001;

int G[maxn];
int color[maxn];	//��iֻţȾ��i��ɫ 
int dfsnum[maxn];	//ʱ���
int minc[maxn];		//���Ĵ�С
int res[maxn];		//iţ������Ҫ�ߵĳ��� 

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&G[i]);
	for(int i=1;i<=n;i++){	//��iֻţ 
		for(int j=i,cnt=0;;j=G[j],cnt++)	//cnt��¼ʱ��� 
			if(color[j]==0){		//��δ���ʹ� 
				color[j]=i;	//Ⱦ�ɵ�iֻţ����ɫ 
				dfsnum[j] = cnt;
			}
			else if(color[j]==i){	//iţ֮ǰ�߹� 
				minc[i] = cnt - dfsnum[j];
				res[i] = dfsnum[j];	//iţ������Ҫ�ߵĳ��� 
				printf("%d\n",cnt);
				break;
			}
			else{	//���˱��ţ�߹���·�� 
				minc[i] = minc[color[j]];	//��ɫ���������ţ
				res[i] = cnt + max(res[color[j]]-dfsnum[j],0);	//i�����·��=i��j���·��+j������·�� 
				printf("%d\n",res[i]+minc[i]);
				break;
			}
	}
	return 0;
}
