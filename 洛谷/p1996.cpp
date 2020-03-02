#include<cstdio>

const int maxn = 101;
bool isvisit[maxn];

int main(){	//暴力模拟 
	int n,m; //n个人,每次从1开始数,数到m的人出列 
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
