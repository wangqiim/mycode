#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1003;
int d[maxn];

int main() {
	int T, n, x;
	cin >> T;
	while (T--) {
		cin >> n >> x;
		int u, v;
		for (int i = 0; i < n; i++) 
			d[i] = 0;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			d[u]++;
			d[v]++;
		}
		if (d[x] <= 1) 
			puts("Ayush");
		else {
			if (n % 2 == 0)
				puts("Ayush");
			else
				puts("Ashish");
		}
	}
	return 0;
}
