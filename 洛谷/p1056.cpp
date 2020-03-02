#include<cstdio>
#include<algorithm>
using namespace std;

struct row_col{
	int no;
	int times;
};

const int maxn = 1001;
int nums[maxn][maxn]={};
row_col row[maxn]={false};	//��ʼʱrow[1]=0��ʾ��һ�к͵ڶ���֮����Ҫ���������� 
row_col col[maxn]={false};

bool cmp1(row_col a,row_col b){
	if(a.times != b.times)
	return a.times>b.times;
	else return a.no<b.no;
}

bool cmp2(row_col a,row_col b){	//Ŀ���ǰ�no˳����� 
	return a.no<b.no;
}

int main(){
	for(int i=0;i<maxn;i++){
		row[i].no = i;		col[i].no = i;
		row[i].times = 0; 	col[i].times = 0;
	}
	int m,n,k,l,d;	//m��n��,k�����,l���ݵ�,dλ����
	scanf("%d %d %d %d %d",&m,&n,&k,&l,&d);
	int x,y,p,q;
	for(int i=0,t;i<d;i++){//(x,y)��(p,q)��˵����Ļ� 
		scanf("%d %d %d %d",&x,&y,&p,&q);
		if(x==p){	//��Ҫ��col���� 
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
