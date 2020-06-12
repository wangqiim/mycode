#include<cstdio>
#include<algorithm>
using namespace std;
 
const int maxn = 51;
const int maxm = 51;
int a[maxn][maxm] = {0};
int row[maxn] = {0};
int col[maxm] = {0};
//Ashish first 
//Vivek
int main() {
	int t;
	int n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) row[i] = 0;
		for (int j = 0; j < m; j++) col[j] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 1) {
					row[i] = 1;
					col[j] = 1;
				}
			}
		int empty_row = 0;
		int empty_col = 0;
		for (int i = 0; i < n; i++) if (row[i] == 0) 
			empty_row++;		
		for (int j = 0; j < m; j++) if (col[j] == 0)
			empty_col++;
		int ans = min(empty_row, empty_col);
		if (ans % 2 == 0) puts("Vivek");
		else puts("Ashish");
	}
	return 0;
}
