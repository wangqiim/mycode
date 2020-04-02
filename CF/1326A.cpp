#include<cstdio>

int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		putchar('2');
		for(int i=1;i<n;i++)
			putchar('3');
		putchar('\n');
	}
	return 0;
} 
