#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int t;
	int n, m, k;	//N����,m������k���� 
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		if(m <= n / k) {
			printf("%d\n", m);
		} else {
			if((m - (n/k)) % (k-1) == 0)
				printf("%d\n", n / k - (m - (n/k)) / (k-1) );
			else{
				printf("%d\n", n / k - (m - (n/k)) / (k-1) - 1);
			}
		}
	}
	return 0;
}
