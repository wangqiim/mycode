#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

 
int main() {
    int t;
    long long a, b, n, m;
    scanf("%lld", &t);
    while (t--) {
    	scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    	long long mi = min(a, b);
    	if (mi < m)
    		puts("No");
		else {
			if (a + b >= n + m)
				puts("Yes");
			else 
				puts("No");
		}
	}
    return 0;
}
