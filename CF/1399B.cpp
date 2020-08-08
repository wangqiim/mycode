#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 55;
int a[maxn];
int b[maxn];
int sub_a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	int ans;
	while (t--) {
		scanf("%d", &n);
		long long ans = 0;	
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		
		int min_a = 0x7fffffff;
		for (int i = 0; i < n; i++) min_a = min(min_a, a[i]);
		for (int i = 0; i < n; i++) {
			sub_a[i] = a[i] - min_a;
			ans += sub_a[i];
		}
		//cout << "ans = " << ans << endl;
		
		int min_b = 0x7fffffff;
		for (int i = 0; i < n; i++) min_b = min(min_b, b[i]);
		for (int i = 0; i < n; i++) {
			if (b[i] - sub_a[i] > min_b) {
				ans += b[i] - sub_a[i] - min_b;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
