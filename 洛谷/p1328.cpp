#include<cstdio>

const int maxn = 200;
//nums[0][1]=-1 表示剪刀对石头,-1表示输
//剪刀 石头 布 蜥蜴人 斯波克 
int nums[5][5]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int numsa[maxn];
int numsb[maxn];

int main(){
	int n,na,nb;
	int resa=0,resb=0;	//小A和小B的得分 
	scanf("%d %d %d",&n,&na,&nb);
	for(int i=0;i<na;i++)
		scanf("%d",&numsa[i]);
	for(int i=0;i<nb;i++)
		scanf("%d",&numsb[i]);
	for(int i=0,a=0,b=0;i<n;i++){
		int j = nums[numsa[a]][numsb[b]];
		if(j>0){
			resa++;	
		}else if(j<0){
			resb++;
		}
		a = (a+1)%na;
		b = (b+1)%nb;
	}
	printf("%d %d",resa,resb);
	return 0;
}
