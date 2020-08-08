#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

int main() {
	int t, l, r;
	scanf("%d", &t);
	int ans;
	while (t--) {
		scanf("%d%d", &l, &r);
		if (r >= 2 * l) {
			printf("%d %d\n", l, 2 * l);
		} else {
			puts("-1 -1");
		}
	}
	return 0;
}
