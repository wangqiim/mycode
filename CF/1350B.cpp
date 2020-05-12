#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
int s[maxn];
int dp[maxn];

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		int ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n; i++){
			scanf("%d",&s[i]);
			dp[i] = 1;
		}
		for(int i = n; i >= 1 ; i--){
			for(int j = i + i ; j <= n; j += i){
				if(s[i] < s[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
