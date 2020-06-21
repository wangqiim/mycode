#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 2003;
int even[maxn];
int odd[maxn];

int main() {
	int t, n;	//N张牌,m个王，k个人
	int a;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int cnt_even = 0;
		int cnt_odd = 0;
		for (int i = 1; i <= 2 * n; i++) {
			scanf("%d",&a);
			if (a % 2 == 0) {
				even[cnt_even] = i;
				cnt_even++;
			} else {
				odd[cnt_odd] = i;
				cnt_odd++;
			}
		}
		if (cnt_odd % 2 == 1) {
			cnt_odd--;
			cnt_even--;
		} else {
			if (cnt_odd > 0)
				cnt_odd -= 2;
			else
				cnt_even -=2;
		}
		for (int i = 0; i < cnt_odd; i += 2) {
			printf("%d %d\n",odd[i], odd[i + 1]);
		}
		for (int i = 0; i < cnt_even; i += 2) {
			printf("%d %d\n",even[i], even[i + 1]);
		}
	}
	return 0;
}
