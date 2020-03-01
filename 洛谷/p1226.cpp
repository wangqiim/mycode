#include<cstdio>

int mypow_mod(int a,int b,int c){	//a^b递归写法 
	if(b==0)
		return 1%c;
	long long res = mypow_mod(a,b>>1,c)%c;	//使用long long防止乘一次就溢出 
	if(b&1)
		return (((a%c)*res)%c)*res%c;	//乘一次就必须立即取余否则可能溢出 
	else
		return res*res%c;
}
int main(){
	int b,p,k;
	scanf("%d %d %d",&b,&p,&k);
	printf("%d^%d mod %d=%d",b,p,k,mypow_mod(b,p,k));
	return 0;
}
