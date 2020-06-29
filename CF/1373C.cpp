#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000006;
int loc[maxn];
 
int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
    	cin >> s;
    	int n = s.size();
    	int sum = 0;
    	int bound = 0;
    	for (int i = 0; i <= n; i++) loc[i] = 0;
    	for (int i = 0; i < n; i++) {
    		if (s[i] == '-') sum++;
    		else sum--;
    		if (sum > bound) {
    			bound = sum;
    			loc[sum] = i + 1;
			}
		}
		long long ans = n;
		for (int i = 1; i <= bound; i++)
			ans += loc[i];
		cout << ans << endl;
	}
    return 0;
}
