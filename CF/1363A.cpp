#include<cstdio>

int main() {
	int T;
	int n, x;
	int a;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &x);
		int even = 0;	//evenµÄ¸öÊı 
		int odd = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if(a % 2 == 0)
				even++;
			else
				odd++;
		}
		if (odd == 0) {
			puts("No");
			continue;
		}
		if(even == 0) {
			if (x % 2 == 1) puts("Yes");
			else puts("No");
		} else {
			if (x <= 1 + even + (odd - 1) / 2 * 2)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
