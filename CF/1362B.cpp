#include<cstdio>
#include<algorithm>
#include<set> 
using namespace std;
 
const int maxn = 1024;
int a[maxn];
int s[maxn];
 
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
    	scanf("%d", &n);
    	for (int i = 0; i < 1024; i++) s[i] = 0;
    	for (int i = 0; i < n; i++) {
    		scanf("%d", &a[i]);
    		s[a[i]] = 1;
		}
		int ans = -1;
		for (int i = 1; i < 1024; i++) {
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (s[a[j] ^ i] == 0) 
					flag = false;
			}
			if (flag == true) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}