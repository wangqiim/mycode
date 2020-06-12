#include<iostream>
#include<algorithm>
using namespace std;
 
const int maxn = 51;
const int maxm = 51;
char cell[maxn][maxm];
// . # G B
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};
bool vis[maxn][maxm] = {false};
int t, n, m;
 
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
		if (vis[xx][yy] == false && cell[xx][yy] != 'B' && cell[xx][yy] != '#')
			dfs(xx, yy);
	}
}
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool ans = true;
		//初始化vis 
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = false;
		//读入矩阵 
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> cell[i][j];
		//围起来B 
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (cell[i][j] == 'B') {
			for (int k = 0; k < 4; k++) {
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
				if (cell[xx][yy] == 'G')
						ans = false;
				if (cell[xx][yy] == 'B')
						continue;
				cell[xx][yy] = '#';
			}
		}
		if (ans == false) {
			puts("No");
			continue;
		}
		
		if (cell[n - 1][m - 1] == '.' || cell[n - 1][m - 1] == 'G')
			dfs(n - 1, m - 1);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (cell[i][j] == 'G' && vis[i][j] == false)
				ans = false;
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}
