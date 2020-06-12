#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200005;
int a[maxn];
int b[maxn];
int loc_a[maxn];
int shift[maxn];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		loc_a[a[i]] = i;
	}
	for (int i = 1; i <= n ;i++) {
		scanf("%d", &b[i]);
		shift[(i - loc_a[b[i]] + n) % n]++; 
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, shift[i]);
	printf("%d\n", ans);
	return 0;
}
