#include<cstdio>

int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n==1 || m==1){
			puts("YES");
			continue;
		}
		if(n==2 && m==2){
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}
