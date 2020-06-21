#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		string ans = s.substr(0,2);
		int n = s.size();
		for (int i = 3; i < n; i += 2)
			ans.push_back(s[i]);
		cout << ans << endl;
	}
	return 0;
}
