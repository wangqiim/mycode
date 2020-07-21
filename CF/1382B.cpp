#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 100005;
int a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int flag = 1;
		int le = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (flag && a[i] != 1) {
				flag = 0;
				le = i;
			}
		}
		if (flag == 1) {
			if (n % 2 == 0)
				puts("Second");
			else 
				puts("First");
		} else {
			if (le % 2 == 0) {
				puts("First");
			} else {
				puts("Second");
			}
		}
	}
	return 0;
}
