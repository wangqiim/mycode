#include<cstdio>
#include<set>
using namespace std;

const int maxn = 1003;
int n,m;	//n¸ö¶¥µã,mÌõ±ß
int fa[maxn];
void initfa(){
	for(int i=1; i<=n; i++) fa[i] = i;
	return;
}
int findfa(int x){
	if(fa[x]!=x)
		fa[x] = findfa(fa[x]);
	return fa[x];
}
void merge(int u,int v){
	fa[findfa(u)] = findfa(v);
	return;
}

int main(){
	int u,v;
	set<int> se;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		scanf("%d",&m);
		initfa();
		se.clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			merge(u,v);
		}
		for(int i=1;i<=n;i++)
			se.insert(findfa(i));
		printf("%d\n",se.size()-1);
	}
	return 0;
}
