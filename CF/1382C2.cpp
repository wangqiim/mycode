#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);//输入加速 
	cout.tie(0);//输出加速 
	int t, n;
	string a, b, a1;
	vector<int> ans;
	cin >> t;
	while (t--) {
		ans.clear();
		cin >> n;
		cin >> a >> b;
		int k = 1;
		int add = 1;
		int dec = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (a[0] != b[i]) {
				ans.push_back(i + 1);
			} else {
				ans.push_back(1);
				ans.push_back(i + 1);
			}
			if (k % 2 == 1) {
				a[0] = (a[dec] == '0'?'1':'0');
				dec--;
			} else {
				a[0] = a[add]; 
				add++;
			}
			k++;
		}
		int size = ans.size();
		cout<< size << " ";
		for (int i = 0; i < size; i++) {
			cout << ans[i] << " ";
		}cout << endl;
	}
	return 0;
}

