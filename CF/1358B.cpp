#include<cstdio>
#include<algorithm>
using namespace std;
 
const int maxn = 100005;
int a[maxn];
 
int main(){
	int t;
	int n;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		int ans = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] <= i + 1) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans + 2);
	}
	return 0;
}
