#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int t;
	int n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d", &n);
		if (n % 4 == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
