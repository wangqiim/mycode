#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

char x,y;
char ex,ey;
void read(){
	x = getchar();
	y = getchar();
	getchar();
	ex = getchar();
	ey = getchar();
}

int main(){
	read();
	int res=0;
	int dx = ex-x;
	int dy = ey-y;
	printf("%d\n",max(abs(dx),abs(dy)));
	while(dx!=0&&dy!=0){
		if(dx>0&&dy>0){
			printf("RU\n");
			dx--;dy--;
		}else if(dx>0&&dy<0){
			printf("RD\n");
			dx--;dy++;
		}else if(dx<0&&dy>0){
			printf("LU\n");
			dx++;dy--;
		}else{
			printf("LD\n");
			dx++;dy++;
		}
	}
	while(dx!=0){
		if(dx>0){
			putchar('R');
			putchar('\n');
			dx--;
		}
		else{
			putchar('L');
			putchar('\n');
			dx++;
		}
	}
	while(dy!=0){
		if(dy>0){
			putchar('U');
			putchar('\n');
			dy--;
		}
		else{
			putchar('D');
			putchar('\n');
			dy++;
		}
	}
	return 0;
}
