#include<cstdio>
#include<algorithm>
using namespace std;
 
int main() {
    int t;
	long long a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &a, &b);
        if (a < b) swap(a,b);
        if (a == b) {
        	puts("0");
        	continue;
		}
        if (a % b != 0) {
            puts("-1");
        } else {
            long long temp = a / b;
			long long ans = 0;
			while (temp % 8 == 0) {
				temp /= 8;
				ans++;
			}
			while (temp % 4 == 0) {
				temp /= 4;
				ans++;
			}
			while (temp % 2 == 0) {
				temp /= 2;
				ans++;
			}
			if (temp == 1)
				printf("%lld\n", ans);
			else puts("-1");
        }
    }
    return 0;
}