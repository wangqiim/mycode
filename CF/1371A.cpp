#include<cstdio>
#include<iostream>
using namespace std;
 
int main() {
	int t;
	int n;
	scanf("%d",&t);
	while (t--) {	
		scanf("%d",&n);
		printf("%d\n", (n + 1) / 2);
	}
	return 0;
}
