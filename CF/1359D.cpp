#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 100005;
int a[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for (int mx = -30; mx <= 30; mx++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mx) {
				sum = 0;
				continue;
			}
			if (sum < 0)
				sum = 0;
			sum += a[i];
			ans = max(ans, sum - mx);			
		}
	}
	printf("%d\n", ans);
	return 0;
}
