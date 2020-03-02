#include<cstdio>
#include<algorithm>
using namespace std;

struct row_col{
	int no;
	int times;
};

const int maxn = 1001;
int nums[maxn][maxn]={};
row_col row[maxn]={false};	//初始时row[1]=0表示第一行和第二行之间需要被隔开几次 
row_col col[maxn]={false};

bool cmp1(row_col a,row_col b){
	if(a.times != b.times)
	return a.times>b.times;
	else return a.no<b.no;
}

bool cmp2(row_col a,row_col b){	//目的是按no顺序输出 
	return a.no<b.no;
}

int main(){
	for(int i=0;i<maxn;i++){
		row[i].no = i;		col[i].no = i;
		row[i].times = 0; 	col[i].times = 0;
	}
	int m,n,k,l,d;	//m行n列,k条横道,l条纵道,d位话痨
	scanf("%d %d %d %d %d",&m,&n,&k,&l,&d);
	int x,y,p,q;
	for(int i=0,t;i<d;i++){//(x,y)与(p,q)有说不完的话 
		scanf("%d %d %d %d",&x,&y,&p,&q);
		if(x==p){	//需要用col隔开 
			t = min(y,q);
			col[t].times++;
		}else{
			t = min(x,p);
			row[t].times++;
		}
	}
	sort(row,row+maxn,cmp1);
	sort(col,col+maxn,cmp1);
	sort(row,row+k,cmp2);
	sort(col,col+l,cmp2);
	for(int i=0;i<k;i++){
		printf("%d",row[i].no);
		if(i==k-1)
			printf("\n");
		else 
			printf(" ");
	}
	for(int i=0;i<l;i++){
		printf("%d",col[i].no);
		if(i==l-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}
