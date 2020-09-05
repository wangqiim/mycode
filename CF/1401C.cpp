#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int maxn = 100005;
int a[maxn];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		vector<int> prim;
		vector<int> non_prim_index;
		vector<int> ans;
		scanf("%d", &n);
		int mi = 0x7fffffff;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mi = min(mi, a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] % mi != 0) {
				non_prim_index.push_back(i);	//记录索引 
			} else {
				prim.push_back(a[i]);	//记录值 
			}
		}
		sort(prim.begin(), prim.end());
		int non_n = non_prim_index.size();
		int ind = 0;	//ans数组 
		int i = 0, j = 0;
		for (; i < non_n; i++) {
			while (ind < non_prim_index[i]) {
				ans.push_back(prim[j++]);
				ind++;
			}
			ans.push_back(a[non_prim_index[i]]);
			ind++;
		}
		for (; ind < n; ind++) {
			ans.push_back(prim[j++]);
		}
		bool flag = true;
		for (int i = 1; i < n; i++) {
			if (ans[i - 1] > ans[i]) {
				flag = false;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
