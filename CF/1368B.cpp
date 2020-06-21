#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s = "codeforces";

int main() {
	long long k;
	cin >> k;
	long long bound = 1;
	while(pow(bound,10ll) < k) {
		bound++;
	}
	int cnt = 10;
	long long mul = pow(bound,10);
	while (mul / bound * (bound - 1) >= k) {
		mul = mul / bound * (bound - 1);
		cnt--;
	}
	string ans = "";
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < bound; j++)
			ans.push_back(s[i]);
	}
	for (int i = cnt; i < 10; i++) {
		for (int j = 0; j < bound - 1; j++) {
			ans.push_back(s[i]);
		}
	}
	cout << ans;
	return 0;
}
