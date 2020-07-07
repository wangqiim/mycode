#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

const int maxn = 300005;
int a[maxn];

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
    	scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		if (a[0] < a[n - 1])
			puts("YES");
		else
			puts("NO");
	}
    return 0;
}
