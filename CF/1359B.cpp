#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		int flag = 1;
		if(2 * x > y)	//ÓÃ1 * 2×©¿é»®Ëã 
			flag = 2;
		string a;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			a.push_back('*');
			for (int j = 0; j < m; j++) {
				if (a[j] == '.') {
					if(a[j + 1] != '.' || flag == 1) {
						ans += x;
					} else {
						ans += y;
						j++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
