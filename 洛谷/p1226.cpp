#include<cstdio>

int mypow_mod(int a,int b,int c){	//a^b�ݹ�д�� 
	if(b==0)
		return 1%c;
	long long res = mypow_mod(a,b>>1,c)%c;	//ʹ��long long��ֹ��һ�ξ���� 
	if(b&1)
		return (((a%c)*res)%c)*res%c;	//��һ�ξͱ�������ȡ����������� 
	else
		return res*res%c;
}
int main(){
	int b,p,k;
	scanf("%d %d %d",&b,&p,&k);
	printf("%d^%d mod %d=%d",b,p,k,mypow_mod(b,p,k));
	return 0;
}
