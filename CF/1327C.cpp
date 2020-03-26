#include<cstdio>

int main(){
	int n,m,k;
	char U = 'U',D = 'D',R = 'R',L = 'L';
	scanf("%d %d",&n,&m);
	printf("%d\n",m*n-1+m-1+n-1);
	for(int i=0;i<m-1;i++)
		putchar(L);
	for(int i=0;i<n-1;i++)
		putchar(D);
	int up = 1;
	int t = m;
	while(1){
		if(up==1){
			for(int i=0;i<n-1;i++)
				putchar(U);
			up = 1-up;
		}else{
			for(int i=0;i<n-1;i++)
				putchar(D);
			up = 1-up;
		}
		if(t==1)
			break;	
		putchar(R);
		t--;
	}
	return 0;
}
