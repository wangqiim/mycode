#include<cstdio>

int main(){
	int t,n;
	scanf("%d",&t);
	int pp,pc;
	int p,c;
	while(t--){
		scanf("%d",&n);
		bool res = true;
		pp=0,pc=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&p,&c);
			int dp = p-pp,dc = c-pc;
			if(dc>dp||dc<0)
				res = false;
			pp = p;pc = c;
		}
		if(res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
