#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 200005;
long long acc[maxn];
int a[maxn];


int main() {
	int t, n, k, z;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i == 0)
				acc[i] = a[i];
			else 
				acc[i] = acc[i - 1] + a[i];
		}
		long long ans = 0;
		for (int i = 0; i <= k; i++) {
			int zz = z;	//左移次数 
			long long t = 0;
			if (i != 0)
				t += acc[i - 1];
			int step = k - i + 1;	//剩余步数 	
			int flag = 0;
			int ind = i;
			while(zz >= 0 && step > 0) {
				if (flag % 2 == 0) {
					t += a[i];
					zz--;
					ind = i;
				}
				else {
					ind = i + 1;
					t += a[i + 1];
				}
				step--;
				flag++;
			}
			t += acc[ind + step] - acc[ind];
			ans = max(ans, t);
		}
		printf("%d\n",ans);
	}
	return 0;
}
