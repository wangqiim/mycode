#include<cstdio>

const int maxn = 10004;
const int maxm = 200005;

int z[maxm],x[maxm],y[maxm];
int fa[maxn];

int find_fa(int x){
	fa[x] = (fa[x]==x?fa[x]:find_fa(fa[x]));
	return fa[x];
}

void merge(int a,int b){
	int faa = find_fa(a);
	int fab = find_fa(b);
	fa[faa] = fab;
	return ;
}

int main(){
	int N,M;	//N个元素,M个操作
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&z[i],&x[i],&y[i]);
	}
	for(int i=0;i<maxn;i++)
		fa[i]=i;
	for(int i=0;i<M;i++){
		if(z[i]==1)	//合并 
			merge(x[i],y[i]);
		else		//查询 
			if(find_fa(x[i])==find_fa(y[i]))
				printf("Y\n");
			else
				printf("N\n");
	}
	return 0;
}
