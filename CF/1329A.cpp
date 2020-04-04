#include<cstdio>

const int maxn = 1000006;
int l[maxn];
int p[maxn];
long long sum = 0;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&l[i]);
	for(int i=0;i<m;i++){
		sum += l[i];
		if(i==0)
			p[i] = n-l[i]+1-i;
		else{
			p[i] = n-l[i]+1-i;
			if(p[i]<=0){	//剩余的位置填不下p[i]了 
				printf("-1\n");
				return 0;
			}
		}
	}
	if(sum<n){
		printf("-1\n");
		return 0;
	}
	int left_bound = 1;
	for(int i=m-1;i>0;i--){
		if(i==m-1){
			p[i] = 1;
			left_bound = p[i]+l[i]; 
		}else{
			if(p[i]>left_bound){
				p[i] = left_bound;
				left_bound = p[i]+l[i];
			}
			else break;
		}
	}
	for(int i=0;i<m;i++)
		printf("%d ",p[i]);
	putchar('\n');
	return 0;
}
