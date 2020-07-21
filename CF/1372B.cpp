#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 100005;

int main() {
	int t,n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int t = 0;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				t = i;
				break;	
			}
		}
		if (t == 0) {
			printf("%d %d\n", 1, n - 1);
		} else {
			printf("%d %d\n", n / t, n / t *(t - 1));
		}
	}
	return 0;
}
