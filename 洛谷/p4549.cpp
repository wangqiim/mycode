#include<cstdio>

inline int gcd(int a, int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int n,res,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a<0) a = -a;
		if(a==0) continue;
		if(i==0)
			res = a;
		else 
			res = gcd(res,a);
	}
	printf("%d\n",res);
	return 0;
} 
