#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
#include<queue> 
#include<stack>
using namespace std;

const int maxn = 200005;
int res[maxn];

int main() {
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		int cnt = 0;
		vector<int> ans;
		stack<int> s1, s0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (s0.empty()) {
					cnt++;
					s1.push(cnt);
					ans.push_back(cnt);
				} else {
					ans.push_back(s0.top());
					s1.push(s0.top());
					s0.pop();
				}
			} else {
				if (s1.empty()) {
					cnt++;
					s0.push(cnt);
					ans.push_back(cnt);
				} else {
					ans.push_back(s1.top());
					s0.push(s1.top());
					s1.pop();
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
