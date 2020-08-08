#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;


int main() {
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		int ans = 0x7fffffff;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++){
				if (i == j) {
					int cnt = 0;
					for (int k = 0; k < n; k++)  if (s[k] == '0' + i) cnt++;
					ans = min(ans, n - cnt);
				} 
				else {
					int cnt = 0;
					char pre = '-';
					for (int k = 0; k < n; k++) {
						if (s[k] == '0' + i) {
							if (pre == '-' || pre == '0' + j) {
								cnt++;
								pre = '0' + i;
							}
						}
						if(s[k] == '0' + j) {
							if (pre == '-' || pre == '0' + i) {
								cnt++;
								pre = '0' + j;
							}
						}
					}
					if(cnt % 2 == 0)
						ans = min(ans, n - cnt);
					else
						ans = min(ans, n - cnt + 1);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

