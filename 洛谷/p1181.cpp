#include<cstdio>

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int s=0;	//当前段累计和 
	int res = 1;
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x+s>m){
			res++;
			s=x;
		}else{
			s+=x;
		}
	}
	printf("%d",res);
	return 0;
}
