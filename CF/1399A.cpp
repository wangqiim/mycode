#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

const int maxn = 55;
vector<int> nums;

int main() {
	int t, n, a;
	scanf("%d", &t);
	int ans;
	while (t--) {
		scanf("%d", &n);
		nums.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			nums.push_back(a);
		} 
		sort(nums.begin() ,nums.end());
		int s = nums.size();
		bool ans = true;
		for (int i = 1; i < s; i++) {
			if (nums[i] - nums[i - 1] > 1) ans = false;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
