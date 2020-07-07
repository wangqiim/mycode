#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
 
vector<int> a;
vector<int> ans;
 
int main() {
	int t, n, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n); 
		ans.clear();
		a = vector<int>(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		bool flag = true;
		while (flag) {
			int MEM = n;	
			//先找到MEM
			set<int> st;
			for (int i = 0; i < n; i++)	st.insert(a[i]);
			for (int i = 0; i < n; i++)
				if (st.count(i) == 0) {
					MEM = i;
					break;
				}
			if (MEM == n) {	
				//遍历a，找到替换的位置。 
				for (int i = 0; i < n; i++) {
					if (a[i] != i) {
						ans.push_back(i);
						a[i] = MEM;
						break;
					}
					if (i == n - 1) flag = false;
				}
			} else {
				ans.push_back(MEM);
				a[MEM] = MEM;
			}	
		}
		printf("%d\n", ans.size());
		for (int i = 0, size = ans.size(); i < size; i++)
			printf("%d ", ans[i] + 1);
		puts("");
	}
	return 0;
} 