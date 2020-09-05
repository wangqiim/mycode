#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;


int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int n = s.size();
		vector<int> nums;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (sum > 0)
					nums.push_back(sum);
				sum = 0;
			} else {
				sum++;
			}
		}
		if (sum > 0) nums.push_back(sum);
		int nn = nums.size();
		sort(nums.begin(), nums.end());
		int ans = 0;
		for (int i = nn - 1; i >= 0; i-= 2) {
			ans += nums[i];
		}
		cout << ans << endl;
	}
	return 0;
}
