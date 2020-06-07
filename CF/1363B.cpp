#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1003;
int acc_0[maxn], acc_1[maxn];

int main() {
	int T;
	string s;
	int ans;
	cin >> T;
	while (T--) {
		cin >> s;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (s[i] == '0') {
					acc_0[i] = 1;
					acc_1[i] = 0;
				} else {
					acc_0[i] = 0;
					acc_1[i] = 1;
				}
			} else {
				if (s[i] == '0') {
					acc_0[i] = acc_0[i - 1] + 1;
					acc_1[i] = acc_1[i - 1];
				} else {
					acc_0[i] = acc_0[i - 1];
					acc_1[i] = acc_1[i - 1] + 1;
				}
			}
		}
		ans = n;
		for (int i = 0; i < n; i++) {
			//0.....0 1..1
			//1.....1 0..0
			ans = min(ans, acc_1[i] + acc_0[n - 1] - acc_0[i]);
			ans = min(ans, acc_0[i] + acc_1[n - 1] - acc_1[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
