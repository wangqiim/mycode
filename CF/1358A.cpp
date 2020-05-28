#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&m);
		if (n % 2 == 1 && m % 2 == 1)
			printf("%d\n", n * m / 2 + 1);
		else
			printf("%d\n", n * m / 2);
	}
	return 0;
}
