#include<cstdio>
#include<iostream>
using namespace std;

long long a[20];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++){
		long long t;
		scanf("%lld", &t);
		for (int j = 0; j < 20; j++)
			if (t & (1LL << j)) 
				a[j]++;
	}	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long t = 0;
		for (long long j = 0; j < 20; j++)
			if (a[j]) {
				t |= (1LL << j);
				a[j]--;
			}
		ans += t * t;
	}
	printf("%lld", ans);
	return 0;
}

