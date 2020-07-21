#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;


int main() {
	int t, n;
	scanf("%d", &t);
	int x, y, z;
	while (t--) {
		scanf("%d%d%d", &x, &y, &z);
		if (x != y && y != z && x != z) {
			puts("NO");
		} else {
			int a, b, c;
			if (y == z) {
				if (x > y) {
					puts("NO");
					continue;
				}
				a = b = x;
				c = y;
			} else if (x == y){
				if(z > x) {
					puts("NO");
					continue;
				}
				b = c = z;
				a = x;
			} else {
				if (y > x) {
					puts("NO");
					continue;
				}
				a = c = y;
				b = x;
			}
			puts("YES");
			printf("%d %d %d\n", a, b, c);	
		}
	}
	return 0;
}
