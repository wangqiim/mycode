#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n",3 * n + 4);
	int line = 0;
	for (int i = n + 1;i >= 0;i--) {
		if (i == n + 1) {
			printf("%d 0\n", i);
			printf("%d 1\n", i);
		}
		else if (i == 0)
		{
			printf("%d %d\n", i, line);
			printf("%d %d\n", i, line+1);
		}
		else
		{
			printf("%d %d\n", i, line);
			printf("%d %d\n", i, line + 1);
			printf("%d %d\n", i, line + 2);
			line++;
		}
	}
	return 0;
}
