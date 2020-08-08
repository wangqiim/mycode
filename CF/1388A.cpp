#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n <= 30)
			puts("NO");
		else {
			puts("YES");
			if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14)
				printf("%d %d %d %d\n", 6, 10, 15, n - 31);
			else 
				printf("%d %d %d %d\n", 6, 10, 14, n - 30);
		}
	}
	return 0;
}
