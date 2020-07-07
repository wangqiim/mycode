#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 302;
const int maxm = 302;
int a[maxn][maxm];

int main() {
	int t;
	scanf("%d",&t);
	int n, m;
	while (t--) {
		scanf("%d%d", &n, &m);
		bool ans = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				if (i == 0 && j == 0){
					if (a[i][j] > 2)
						ans = false;	
					a[i][j] = 2;
				} else if (i == 0 && j == m - 1){
					if (a[i][j] > 2)
						ans = false;	
					a[i][j] = 2;
				} else if (i == n - 1 && j == 0) {
					if (a[i][j] > 2)
						ans = false;	
					a[i][j] = 2;
				} else if (i == n - 1 && j == m - 1){
					if (a[i][j] > 2)
						ans = false;	
					a[i][j] = 2;
				} else if (i == 0 && j != 0 && j != m - 1) {
					if (a[i][j] > 3) 
						ans = false;
					a[i][j] = 3;
				} else if (i == n - 1 && j != 0 && j != m - 1) {
					if (a[i][j] > 3) 
						ans = false;
					a[i][j] = 3;
				} else if (i != 0 && i != n - 1 && j == 0) {
					if (a[i][j] > 3) 
						ans = false;
					a[i][j] = 3;
				} else if (i != 0 && i != n - 1 && j == m - 1) {
					if (a[i][j] > 3) ans = false;
					a[i][j] = 3;
				} else {	
					if (a[i][j] > 4) ans = false;
					a[i][j] = 4;
				}
			}
		}
		if (ans) {
			puts("YES");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					printf("%d ",a[i][j]);
				puts("");
			}
		} 
		else {
			puts("NO");
		}
	}
	return 0;
}
