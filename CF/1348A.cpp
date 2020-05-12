#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 31;
int mypow[maxn]={1};

int main(){
	int t,n;
	int ans;
	scanf("%d",&t);
	for(int i=1;i<=30;i++)
		mypow[i] = mypow[i-1]*2;
	while(t--){
		scanf("%d",&n);
		ans = mypow[n];
		for(int i=1;i<n/2;i++)
			ans += mypow[i];
		for(int i=n/2;i<n;i++)
			ans -= mypow[i];
		printf("%d\n",ans);
	}
	return 0;
}
