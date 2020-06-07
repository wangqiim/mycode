
#include<cstdio>
#include<algorithm>
using namespace std;
 
int main() {
    int t;
    long long n;
    scanf("%d", &t);
    while (t--) {
    	scanf("%lld", &n);
    	long long ans = 0LL;
    	while (n) {
    		ans += n;
    		n >>= 1;
		}
		printf("%lld\n", ans);
	}
    return 0;
}