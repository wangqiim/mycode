#include<cstdio>

const int maxn = 5003;
int fa[maxn];
void initfa(int n){
	for(int i=0;i<=n;i++)
		fa[i] = i;
	return;
}
int findfa(int x){
	if(fa[x]!=x)
		fa[x] = findfa(fa[x]);
	return fa[x]; 
}
void mergefa(int u,int v){
	int fa_u = findfa(u);
	int fa_v = findfa(v);
	fa[fa_u] = fa_v;
	return;
}

int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	initfa(n);
	int m1,m2;
	for(int i=0;i<m;i++){
		scanf("%d%d",&m1,&m2);
		mergefa(m1,m2);
	}
	int p1,p2;
	for(int i=0;i<p;i++){
		scanf("%d%d",&p1,&p2);
		if(findfa(p1)==findfa(p2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
