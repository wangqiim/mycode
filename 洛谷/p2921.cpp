#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100001;

int G[maxn];
int color[maxn];	//第i只牛染成i颜色 
int dfsnum[maxn];	//时间戳
int minc[maxn];		//环的大小
int res[maxn];		//i牛进环所要走的长度 

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&G[i]);
	for(int i=1;i<=n;i++){	//第i只牛 
		for(int j=i,cnt=0;;j=G[j],cnt++)	//cnt记录时间戳 
			if(color[j]==0){		//还未访问过 
				color[j]=i;	//染成第i只牛的颜色 
				dfsnum[j] = cnt;
			}
			else if(color[j]==i){	//i牛之前走过 
				minc[i] = cnt - dfsnum[j];
				res[i] = dfsnum[j];	//i牛进环所要走的长度 
				printf("%d\n",cnt);
				break;
			}
			else{	//到了别的牛走过的路径 
				minc[i] = minc[color[j]];	//颜色标记是哪条牛
				res[i] = cnt + max(res[color[j]]-dfsnum[j],0);	//i点进环路径=i到j点的路径+j进环的路径 
				printf("%d\n",res[i]+minc[i]);
				break;
			}
	}
	return 0;
}
