#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int t;
	double a, b, c;
	scanf("%d",&t);
	while (t--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		double t = b / c;
		if (a >= c) 
			printf("-1 ");
		else 
			printf("1 ");
		if (a <= c / b)
			printf("-1\n");
		else
			printf("%d\n", (int)b);
		
	}
	return 0;
}
