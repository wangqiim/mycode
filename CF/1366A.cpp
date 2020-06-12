#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b;
		int ans = 0;
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		int d = a - b;
		if (d > b) {
			ans += b;
		} else {
			a -= d * 2;
			b -= d;
			ans += d;
			ans += b / 3 * 2;
			if (b % 3 == 2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
