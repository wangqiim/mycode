#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 302;
int g[maxn][maxn];
 
int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
    	scanf("%d%d", &n, &k);
    	int kk = k;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			g[i][j] = 0;
    	for (int i = 0; i < n && k > 0; i++) {
    		g[i][i] = 1;
    		k--;
		}
		int x, y;
    	int ri = 1;
    	while (k > 0) {
    		x = ri;
    		y = 0;
    		while(y < n && k > 0) {
    			g[x][y] = 1;
    			k--;
    			x = (x + 1) % n;
    			y++;
			}
			ri++;
		}
		
		long long ans = 0;
		if (kk % n == 0)
			puts("0");
		else
			puts("2");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", g[i][j]);
			}
			puts("");
		}
	}
    return 0;
}
