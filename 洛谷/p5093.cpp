#include<cstdio>

const int maxn = 100000;
int exist[maxn] = {0};

int main(){	//���⼴����̷������� 
	int n,k;
	scanf("%d %d",&n,&k);
	int res=0;
	int num=0;	//û�����ֳ��ֵĴ���
	int x; 
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(exist[x]==0){	//1~k��x�������� 
			exist[x] = 1;
			num++;
			if(num==k){	//������һ������������ 
				res++;
				for(int j=1;j<=k;j++) exist[j] = 0;
				num = 0;
			}
		}
	}
	printf("%d",res+1);
	return 0;
}
