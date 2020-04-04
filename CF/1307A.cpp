#include<cstdio>

const int maxn = 102;
int a[maxn];

int main(){
	int t,n,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int res = a[0];
		for(int i=1;i<n;i++){
			if(a[i]!=0){
				if(a[i]*i<=d){
					res += a[i];
					d -= a[i]*i;
				}else{
					res += d/i;
					break;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
} 
