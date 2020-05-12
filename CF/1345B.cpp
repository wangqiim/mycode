#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 25821;
int nums[maxn]={0};

int main(){
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<maxn;i++)
		nums[i] = (3 * i * i + i) / 2;
	while(t--){
		scanf("%d",&n);
		int mx = maxn-1;
		int ans = 0;
		while(mx > 0){
			int le = 0, ri = mx;
			while(le < ri){
				int mid = (le + ri + 1) / 2;
				if(n < nums[mid]) ri = mid - 1;
				else le = mid;
			}
			if(le!=0)
				ans++;
			mx = ri;
			n -= nums[ri];
		}
		printf("%d\n",ans);
	}
	return 0;
}
