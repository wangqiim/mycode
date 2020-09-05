#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

int main() {
	int t, n, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		if (k <= n) {
			if ((n%2) != (k%2))
				puts("1");
			else 
				puts("0");
		} else {
			printf("%d\n", k - n);
		}
	}
	return 0;
}
