#include<cstdio>

int main(){
	int t, n, k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(n%2 == 1 && k%2 == 1){
			if(n < k)
				puts("NO");
			else{
				puts("YES");
				for(int i = 0; i < k - 1; i++)
					printf("1 ");
				printf("%d\n", n - (k - 1));
			}
		}else if(n%2 == 1 && k%2 == 0){
			puts("NO");
		}else if(n%2 == 0 && k%2 == 1){
			if(n < k * 2)
				puts("NO");
			else{
				puts("YES");
				for(int i = 0; i < k - 1; i++)
					printf("2 ");
				printf("%d\n", n - 2 * (k - 1));
			}
		}else{
			if(n < k)
				puts("NO");
			else{
				puts("YES");
				for(int i = 0; i < k - 1; i++)
					printf("1 ");
				printf("%d\n", n - (k - 1));
			}
		}
	}
	return 0;
}
