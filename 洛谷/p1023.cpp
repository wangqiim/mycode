#include<cstdio>
#include<cmath>

const int maxn = 100001;
int price[maxn];	//价格 
int num[maxn];	//销量

int main(){
	int pre,k=-1; //预期价格及其对应的索引 
	int x,y;	//每一行的输出
	int m=0;	//索引 
	int input_d;	//输入的变化量 
	int d;//插入中间空缺数据时的变化量
	float umax=1e9,umin=-1e9;
	scanf("%d",&pre);
	int i=0;
	scanf("%d %d",&x,&y);
	price[m] = x;num[m] = y;	//成本,销量
	while(1){
		scanf("%d %d",&x,&y);
		if(x==-1&y==-1) break;
		if(x-price[m] == 1){
			m++;
			price[m] = x;
			num[m] = y;
		}
		else{	//需要插入空缺数据 
			d = (y-num[m])/(x-price[m]);//每增加一元减少的销量
			while(x>price[m]){
				m++;
				price[m] = price[m-1]+1;
				num[m] = num[m-1] + d;
			}
		}
	}
	scanf("%d",&input_d);
	x = price[m];y = num[m];
	while(y>input_d){//销量不会变成0
		m++;
		x+=1;y-=input_d;
		price[m] = x;
		num[m] = y; 
	}
	for(int i=0;i<=m;i++){
		if(price[i]==pre){
			k = i;
			break;
		}
	}
	if(k==-1){
		printf("NO SOLUTION");
		return 0;
	}
	for(int i=0;i<k;i++){
		if((float)((num[k]*(price[k]-price[0])-num[i]*(price[i]-price[0]))/(float)(num[i]-num[k]))<umax)	
		//(预期利润-i利润)/预期销量=单位产品需要补贴的值<umax 
			umax = (float)((num[k]*(price[k]-price[0])-num[i]*(price[i]-price[0]))/(float)(num[i]-num[k]));
	}
	for(int i=k+1;i<=m;i++){
		if((float)((num[i]*(price[i]-price[0])-num[k]*(price[k]-price[0]))/(float)(num[k]-num[i]))>umin)
		//(预期利润-i利润)/预期销量=单位产品需要补贴的值>umin
			umin =  (float)((num[i]*(price[i]-price[0])-num[k]*(price[k]-price[0]))/(float)(num[k]-num[i]));
	}
	
	if(umin>umax) printf("NO SOLUTION");
	else if(umin>0){
		if(fabs(umin-(int)(umin))>1e-6)
			printf("%d",(int)umin+1);
		else
			printf("%d",(int)umin);
	}else if(umax<0){
		if(fabs((int)umax-umax)>1e-6)
			printf("%d",(int)umax-1);
		else
			printf("%d",(int)umax);
	}else{
		printf("0");
	}
	return 0;
}
