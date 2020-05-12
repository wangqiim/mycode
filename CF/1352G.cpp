#include<cstdio>

int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=3){
			puts("-1");
			continue;
		}
		if(n % 4 == 0){ // 2 4 1 3 
			int loop = n/4;
			for(int i = 0; i < loop; i++)
				printf("%d %d %d %d ",2+i*4,4+i*4,1+i*4,3+i*4);
			puts("");
		}else if(n % 4 == 1){ // 2 4 1 3 5
			int loop = n/4;
			for(int i = 0; i < loop; i++)
				printf("%d %d %d %d ",2 + i * 4,4 + i * 4,1 + i * 4,3 + i * 4);
			printf("%d\n",n);
		}else if(n % 4 == 2){// 2 4 1 5 3 6
			int loop = n/4;
			for(int i = 0; i < loop - 1; i++)
				printf("%d %d %d %d ", 2+i*4, 4+i*4, 1+i*4, 3+i*4);
			int index = loop - 1;
			printf("%d %d %d %d %d %d\n",2+index*4,4+index*4,1+index*4,5+index*4,3+index*4,6+index*4);
		}else{	// 2 4 1 5 7 3 6
			int loop = n/4;
			for(int i = 0; i < loop - 1; i++)
				printf("%d %d %d %d ",2 + i * 4,4 + i * 4,1 + i * 4,3 + i * 4);
			int index = loop - 1;
			printf("%d %d %d %d %d %d %d\n",2+index*4,4+index*4,1+index*4,5+index*4,7+index*4,3+index*4,6+index*4);
		}
	}
	return 0;
}
