#include<cstdio>
#include<cmath>

bool a[14]={false},b[27]={false},c[27]={false};//列上，两条斜线上有无元素吗
int loc[14];
int n,res;

void eight_queens(int now){	//现在需要处理的行
	if(now>n){	//输出 
		if(res<3)
			for(int i=1;i<=n;i++){
				if(i!=n) printf("%d ",loc[i]);
				else printf("%d\n",loc[i]);
			}
		res++;
	}
	else
		for(int i=1;i<=n;i++){	//依次尝试放各个位置
			if(!a[i]&&!b[now+i]&&!c[now-i+n]){
				a[i] = true;
				b[now+i] = true;
				c[now-i+n] = true;
				loc[now] = i;
				eight_queens(now+1);				
				a[i] = false;
				b[now+i] = false;
				c[now-i+n] = false;
			}
		}
	return;
}

int main(){
	scanf("%d",&n);
	res = 0;
	eight_queens(1);
	printf("%d",res);
	return 0;
}


/* 暴力递归+剪枝最后一个测试样例会超时 
#include<cstdio>
#include<cmath>

const int maxn = 14;
int n;
int res;
int loc[maxn];	//loc[1]表示第一行皇后放的位置 

void eight_queens(int now){	//现在需要处理的行
	if(now>n){	//输出 
		if(res<3)
			for(int i=1;i<=n;i++){
				if(i!=n) printf("%d ",loc[i]);
				else printf("%d\n",loc[i]);
			}
		res++;
	}
	else
		for(int i=1;i<=n;i++){	//依次尝试放各个位置
			bool flag = true;
			for(int j=1;j<now;j++)	//判断和之前的皇后有没有冲突
				if(loc[j]==i||abs(now-j)==abs(i-loc[j])){//竖斜
					flag = false;
					break;
				}
			if(flag){
			loc[now] = i;
				eight_queens(now+1);
			}	
		}
	return;
}

int main(){
	scanf("%d",&n);
	res = 0;
	eight_queens(1);
	printf("%d",res);
	return 0;
}*/
