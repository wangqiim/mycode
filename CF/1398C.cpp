#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;


map<int, int> cnt;

long long solve(int n) {
	if (n > 1) {
		return ((long long)n)*(n-1)/2;
	} else {
		return 0;
	}
}

int main() {
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		cnt.clear();
		cnt[0] = 1;
		int acc = 0;
		long long ans = 0LL;
		for (int i = 1; i <= n; i++) {
			acc += s[i - 1] - '0';
			//cout << acc - i << endl;
			cnt[acc - i]++;
		}
		map<int, int>::iterator it;
		for (it = cnt.begin(); it != cnt.end(); it++) {
			//cout <<"key = " << it->first << " value  ="<< it->second << endl;
			ans += solve(it->second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

