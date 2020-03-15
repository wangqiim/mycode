#include<cstdio>

#define lowbit(x) ((x)&(-x)) 
const int maxn = 500005;
int c[maxn];
int n,m;

void update(int x,int v){
	for(int i = x; i>0; i -= lowbit(i)){
		c[i] += v;
	}
	return;
}

int getsum(int x){
	int sum=0;
	for(int i = x; i<=n; i += lowbit(i)){
		sum += c[i];	
	} 
	return sum;
}

int main(){
	scanf("%d %d",&n,&m);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		update(i-1,-x);
		update(i,x);
	}
	int o,y,k;
	for(int j=1;j<=m;j++){
		scanf("%d",&o);
		if(o==1){	//Ìí¼Ó 
			scanf("%d %d %d",&x,&y,&k);
			update(y,k);
			update(x-1,-k);
		}else{	//²éÑ¯ 
			scanf("%d",&x);
			printf("%d\n",getsum(x));
		}
	}
	return 0;
}
