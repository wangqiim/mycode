#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	string ans;
	while (t--) {
		cin >> n;
		ans = "";
		int div = n / 4;
		int mod = n % 4;
		for (int i = 0; i < n - div - 1; i++)
			ans.push_back('9');
		if (mod == 0) ans.push_back('9');
		else ans.push_back('8');
		
		for (int i = 0; i < div; i++) 
			ans.push_back('8');
		cout << ans << endl;
	}
	return 0;
}
