#include<cstdio>

const int maxn = 101;
bool isvisit[maxn];

int main(){	//����ģ�� 
	int n,m; //n����,ÿ�δ�1��ʼ��,����m���˳��� 
	scanf("%d %d",&n,&m);
	int begin = 0; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(++begin>n) begin = 1;
			while(isvisit[begin]==true) 
				if(++begin>n) begin = 1;
		}
		printf("%d ",begin);
		isvisit[begin]=true;
	}
	return 0;
}
