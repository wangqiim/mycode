#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 502;
int a[maxn];
int b[maxn];


int main() {
	int t;
	int n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int cnt_0 = 0, cnt_1 = 0;
		for (int i = 0; i < n; i++) 
			scanf("%d", &a[i]);	
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			if (b[i] == 0) cnt_0 = 1;
			else cnt_1 = 1;
		}
		if (cnt_1 && cnt_0) {
			puts("Yes");
		} else {
			bool ans = true;
			for (int i = 1; i < n; i++) {
				if (a[i] < a[i - 1]) {
					ans = false;
					break;
				}
			}
			if (ans) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
