#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

int main() {
	int t;
	int n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		if (n == 1) {
			puts("FastestFinger");
			continue;
		}
		if (n == 2) {
			puts("Ashishgup");
			continue;
		}
		if (n % 2 == 1) {	//如果是奇数 
			puts("Ashishgup");
			continue;
		}
		int flag0 = 0; //在1~sqrt(n)中有最小奇数因
		int flag1 = 0;
		int index;
		for (int i = 3; i <= sqrt(n); i += 2) {
			if (n % i == 0) {
				flag0 = 1;
				flag1 = 1;
				index = i;
				break;
			}
		}
		if (flag0 == 0)	//到sqrt(n)~n中尝试寻找最小奇数因子 
			for (int i = 2; i <= sqrt(n); i++) {
				if ((n % i == 0) && ((n / i) % 2 == 1)){
					flag1 = 1;
					index = n / i;
					break;
				}
			}
		if (flag1) { 	//有奇数因子
		 	if ((n/2) % 2 == 1) { //只有一个因子2 
		 		bool flag2 = 0;
		 		int d = n / index;
			 	for (int i = 2; i <= sqrt(d); i++) {	//有不止一个奇数因子 
					if (d % i == 0){
						if (i % 2 == 1) {
							flag2 = 1;
							break;
						} else if ((d / i) % 2 == 1) {
							flag2 = 1;
							break;
						}
					}
				}
				if (flag2)
					puts("Ashishgup");
				else
					puts("FastestFinger");
			}
			else
				puts("Ashishgup");
		}
		else //无奇数因子 
			puts("FastestFinger");
	}
	return 0;
}
