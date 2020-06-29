#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200005;
long long a[maxn];
long long w[maxn];
 
int main() {
    int t;
    int n, k;
    scanf("%d", &t);
    while (t--) {
		long long ans = 0;
    	scanf("%d%d", &n, &k);
    	for (int i = 0; i < n; i++) 
    		scanf("%lld", &a[i]);
		for (int i = 0; i < k; i++) 
			scanf("%lld", &w[i]);
		sort(a, a + n);
		sort(w, w + k);
		int a_right = n - 1;
		int a_left = 0;
		int w_bound = 0;
		bool flag = 1;	//ÏÈ´Ó×óÍùÓÒ±éÀúw 
		for (int i = 0; i < k; i++) {
			if (w[i] == 1) {
				ans += a[a_right] * 2;
				a_right--;
				if (i == n - 1) w_bound = n;
			} else {
				w_bound = i;
				break;
			}
		}
		for (int i = k - 1; i >= w_bound; i--) {
			ans += a[a_right] + a[a_left];
			a_right--;
			a_left += w[i] - 1;
		}
	
		printf("%lld\n", ans);
	}
    return 0;
}
