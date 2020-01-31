#include<cstdio>
#include<cmath>

bool is_prime(int n){	//����������true�����Ƿ���false�� 
	if(n<=1)
		return false;
	else {
		int sqr = (int)sqrt(n);
		for(int i = 2;i<= sqr;i++){
			if(n%i==0)
				return false;
		}
		return true;
	}
}

struct factor{
	int x;	//������ 
	int cnt;	//���� 
}fac[10];

int main(){
	int n,num = 0; //num���������� 
	int t;
	scanf("%d",&n);
	t = n;
	int sqr = (int)sqrt(n);
	if(n == 1){	//1���⴦�� 
		printf("1=1");
		return 0;
	}
	for(int i = 2;i<=sqr;i++){
		if(n%i==0){
			fac[num].x = i;
			fac[num].cnt = 1;
			n = n/i;
			while(n%i == 0){
				fac[num].cnt++;
				n = n/i;
			}
			num++;
		}
	}
	if(n != 1){
		fac[num].x = n;
		fac[num].cnt = 1;
		num++;
	}
	printf("%d=",t);
	for(int i = 0;i<num;i++){
		if(i != 0)
			printf("*");
		if(fac[i].cnt!=1){
			printf("%d^%d",fac[i].x,fac[i].cnt);
		}
		else 
			printf("%d",fac[i]);
	}
	return 0;
}
