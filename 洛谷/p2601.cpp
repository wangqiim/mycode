#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define DEBUG {printf("wwwwqqqqqq\n");}
typedef unsigned long long ull;

int const p1=92083,p2=69061;
const int maxn = 1003;
const int maxm = 1003;
int a[maxn][maxm];
ull hash1[maxn][maxm];	//hash1[i][j]表示矩阵(1,1)~(i,j)的哈希值(从左到右，从上到下)左上 
ull hash2[maxn][maxm];	//hash3[i][j]表示矩阵(1,m)~(i,j)的哈希值(从右到左，从上到下)右上
ull hash3[maxn][maxm];	//hash2[i][j]表示矩阵(n,1)~(i,j)的哈希值(从左到右，从下到上)左下
ull P1[1003];
ull P2[1003];
int tot = 0;

//中心为(x,y) 
//(i,j)->(x,y)（左上->右下），边长为k的正方形的哈希值
ull sum1(int i,int j,int x,int y,int k) {
	return hash1[x][y] - hash1[i - 1][y] * P2[k] - hash1[x][j - 1] * P1[k] + hash1[i - 1][j - 1] * P1[k] * P2[k];
}

ull sum2(int i,int j,int x,int y,int k) {
	return hash2[x][j] - hash2[i - 1][j] * P2[k]-hash2[x][y + 1] * P1[k]+hash2[i - 1][y + 1] * P1[k] * P2[k];
}

ull sum3(int i,int j,int x,int y,int k) {
	return hash3[i][y] - hash3[x + 1][y] * P2[k]-hash3[i][j - 1] * P1[k] + hash3[x + 1][j - 1] * P1[k] * P2[k];
}

//判断函数 
bool check(int i,int j,int x,int y,int mid)
{
	return sum1(i,j,x,y,mid)==sum2(i,j,x,y,mid)&&sum1(i,j,x,y,mid)==sum3(i,j,x,y,mid);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	P1[0] = 1;
	for (int i = 1; i <= n; i++)
		P1[i] = P1[i - 1] * p1;
	P2[0] = 1;
	for (int i = 1; i <= m; i++)
		P2[i] = P2[i - 1] * p2;
	//二维哈希 
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		hash1[i][j] = hash1[i][j - 1] * p1 + a[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		hash1[i][j] += hash1[i - 1][j] * p2;
		
	for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--)
		hash2[i][j] = hash2[i][j + 1] * p1 + a[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		hash2[i][j] += hash2[i - 1][j] * p2;
		
	for (int i = n; i >= 1; i--) for (int j = 1; j <= m; j++)
		hash3[i][j] = hash3[i + 1][j] * p2 + a[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		hash3[i][j] += hash3[i][j - 1] * p1;
	
	for (int i = 1; i <= n; i++) {	//odd
		for (int j = 1; j <= m; j++) {
			int le = 1, ri = min(min(i, j), min(n - i + 1, m - j + 1));
			while (le < ri) {
				int mid = (le + ri + 1) >> 1;
				if (check(i - mid + 1, j - mid + 1, i + mid - 1, j + mid - 1, 2 * mid - 1)) {
					le = mid;
				}
				else ri = mid - 1;
			}
			tot += le;
//			printf("i = %d, j = %d, tot = %d\n",i,j,tot);
		}
	}
	for (int i = 1; i < n; i++) {	//even
		for(int j = 1; j < m; j++) {	//(i,j) (i + 1, j + 1)的中间为中心，边长2 * le
			int le = 1, ri = min(min(i, j), min(n - (i + 1) + 1, m - (j + 1) + 1));
			while(le < ri) {
				int mid = (le + ri + 1) >> 1;
				if(check(i - mid + 1, j - mid + 1, i + mid, j + mid, 2 * mid))
					le = mid;
				else 
					ri = mid - 1;
			}
			if(check(i - le + 1, j - le + 1, i + le, j + le, 2 * le))
				tot += le;
		}
	}
	printf("%d", tot);
	return 0;
}
/*
5 5
4 2 4 4 4 
3 1 4 4 3 
3 5 3 3 3 
3 1 5 3 3 
4 2 1 2 4 

output：27 
*/ 
