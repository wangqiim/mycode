#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;

const int maxn = 1003;

int main() {
	int t, n;
	string a, b;
	vector<int> ans;
	cin >> t;
	while (t--) {
		ans.clear();
		cin >> n;
		cin >> a >> b;
		for (int i = n - 1; i >= 0; i--) {
			if (a[0] != b[i]) {
				for (int j = 0; j <= i; j++)
					a[j] = (a[j] == '0'?'1':'0');
				reverse(a.begin(), a.begin() + i + 1);
				ans.push_back(i + 1);
			} else {
				a[0] = (a[0] == '0'?'1':'0');
				ans.push_back(1);
				for (int j = 0; j <= i; j++)
					a[j] = (a[j] == '0'?'1':'0');
				reverse(a.begin(), a.begin() + i + 1);
				ans.push_back(i + 1);
			}
		}
		int size = ans.size();
		cout<< size << " ";
		for (int i = 0; i < size; i++) {
			cout << ans[i] << " ";
		}cout << endl;
	}
	return 0;
}

