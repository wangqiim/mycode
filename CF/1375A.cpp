#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;


const int maxn = 102;
int a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i % 2 == 0)
				a[i] = abs(a[i]);
			else a[i] = -abs(a[i]);
		}
		for (int i = 0; i < n; i++)	
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
} 
