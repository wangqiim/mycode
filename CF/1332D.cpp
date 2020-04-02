#include<cstdio>
#include<algorithm>
using namespace std;

int a[4][4];
int flag = 0x20000;

int main(){
	int k;
	scanf("%d",&k);
	printf("3 3\n");
	a[1][1] = k|flag;
	a[1][2] = k;
	a[2][1] = k|flag;
	a[2][2] = k;
	a[3][1] = flag;
	a[3][2] = k|flag;
	a[3][3] = k;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			printf("%d ",a[i][j]);
		}
		putchar('\n');
	}	
}
