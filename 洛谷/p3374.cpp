#include<cstdio>

#define lowbit(x) ((x)&(-x))
const int maxn = 500005;
int c[maxn];	//树状数组 
int n,m;//数组长度,与操作数 

void update(int x,int v){
	for(int i = x; i<=n; i += lowbit(i))
		c[i] += v;
	return;
}

int getsum(int x){
	int sum = 0;
	for(int i = x ; i>0 ; i -= lowbit(i))
		sum += c[i];
	return sum;
}

int main(){
	scanf("%d %d",&n,&m);
	int v;
	for(int i=1;i<=n;i++){
		scanf("%d",&v);
		update(i,v);
	}
	int o,x,y;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&o,&x,&y);
		if(o==1) update(x,y);
		else printf("%d\n",getsum(y)-getsum(x-1));
	}
	return 0;
}
