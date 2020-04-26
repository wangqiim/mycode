#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	int n,a,b,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		double mx = 1.0*(c+d)/n;
		double mn = 1.0*(c-d)/n;
		if((double)(a-b)>mx||(double)(a+b)<mn)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}
