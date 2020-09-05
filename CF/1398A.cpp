#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 50004;
int a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &a[i]);
		if (a[0] == a[n - 1]) {
			puts("-1");
			continue;
		}
		if (a[0] + a[1] <= a[n - 1])
			printf("1 2 %d\n", n);
		else 
			puts("-1");
	}
	return 0;
}
