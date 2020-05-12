#include<cstdio>
#include<cmath>

int ans[10];

int main(){
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x = 0;
		int cnt = 0;
		while(n){
			if(n % 10 != 0)
				ans[cnt++] = (n % 10) * (int)pow(10,x);
			n /= 10;
			x++;
		}
		printf("%d\n",cnt);
		for(int i = 0; i < cnt; i++){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}
