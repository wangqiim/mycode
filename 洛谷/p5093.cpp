#include<cstdio>

const int maxn = 100000;
int exist[maxn] = {0};

int main(){	//该题即找最短非子序列 
	int n,k;
	scanf("%d %d",&n,&k);
	int res=0;
	int num=0;	//没个数字出现的次数
	int x; 
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(exist[x]==0){	//1~k中x还不存在 
			exist[x] = 1;
			num++;
			if(num==k){	//出现了一个完整的序列 
				res++;
				for(int j=1;j<=k;j++) exist[j] = 0;
				num = 0;
			}
		}
	}
	printf("%d",res+1);
	return 0;
}
