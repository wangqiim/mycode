#include<cstdio>

#define lowbit(i) ((i)&(-i))
const int maxn = 1000006;
int c[maxn]={};	//��״����,ԭ����hash[i]:ÿ��Ԫ�س��ֵĸ��� 

int t,k,s;//k���� 
void update(int x,int v){	//����x������+v
	for(int i=x; i<=k; i+=lowbit(i))
		c[i] += v;
	return;
}
int getsum(int x){	//����ǰx������֮��
	int sum = 0;
	for(int i=x; i>=1; i-=lowbit(i))
		sum += c[i];
	return sum;
}

int solve(int x){	//����ʣ�����е�xС��Ԫ�أ����Ұ���ɾȥ�� 
	//���ֲ���
	int left = 1,right = k;
	int mid;
	while(left<right){
		mid = (left+right)/2;
		if(getsum(mid)>=x)
			right = mid;
		else
			left = mid+1;
	} 
	update(left,-1);	//ɾȥ�������
	return left;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++) update(i,1);
		for(int i=1;i<=k;i++){
			scanf("%d",&s);	//ʣ�����еĵ�s+1С
			printf("%d",solve(s+1));
			if(i!=k)
				putchar(' ');
			else
				putchar('\n');
		}
	}
	return 0;
}

