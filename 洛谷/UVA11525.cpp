#include<cstdio>

#define lowbit(i) ((i)&(-i))
const int maxn = 1000006;
int c[maxn]={};	//树状数组,原数组hash[i]:每个元素出现的个数 

int t,k,s;//k个数 
void update(int x,int v){	//给第x个数字+v
	for(int i=x; i<=k; i+=lowbit(i))
		c[i] += v;
	return;
}
int getsum(int x){	//返回前x个数字之和
	int sum = 0;
	for(int i=x; i>=1; i-=lowbit(i))
		sum += c[i];
	return sum;
}

int solve(int x){	//返回剩余数中第x小的元素，并且把它删去。 
	//二分查找
	int left = 1,right = k;
	int mid;
	while(left<right){
		mid = (left+right)/2;
		if(getsum(mid)>=x)
			right = mid;
		else
			left = mid+1;
	} 
	update(left,-1);	//删去这个数字
	return left;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++) update(i,1);
		for(int i=1;i<=k;i++){
			scanf("%d",&s);	//剩余数中的第s+1小
			printf("%d",solve(s+1));
			if(i!=k)
				putchar(' ');
			else
				putchar('\n');
		}
	}
	return 0;
}

