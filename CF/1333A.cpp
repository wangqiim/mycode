#include<cstdio>

int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==n&&j==m)
					putchar('W');
				else
					putchar('B');
			}
			putchar('\n');
		}
	}
	return 0;
} 
