#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath> 
#include<vector>
#include<map>
using namespace std;

int main() {
	int t;
	int x1, y1, z1;
	int x2, y2, z2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &x1, &y1, &z1);
		scanf("%d %d %d", &x2, &y2, &z2);
		int ans = 0;
		ans += min(z1, y2) * 2; //2 - 1
		int temp = min(z1, y2);
		z1 -= temp; 
		y2 -= temp;
		z2 -= min(x1, z2);//0 - 2
		z2 -= min(z1, z2);
		ans -= min(y1, z2) * 2; //2 - 2
		printf("%d\n",ans);
	}
	return 0;
}
