#include<algorithm>
#include<vector>
#include<cmath>
#include<stdio.h>
using namespace std;
 
typedef long long ll;
const int maxn = 100005;
const int maxm = 200005;

vector<int> prime[maxm];
 
int main() {
	int n;
	ll a, ans = 1;
	scanf("%d",&n);
	for (int i = 0;i < n;i++){
		scanf("%lld",&a);
		for (int j = 2;j <= sqrt(a);j++){
			if (a % j == 0){
				ll cnt = 0;
				while (a % j == 0){
					a /= j;
					cnt++;
				}
				prime[j].push_back(cnt);
			}
		}
		if (a > 1)
			prime[a].push_back(1);
	}
	for (ll i = 2;i < maxm; i++){
		if (prime[i].size() < n - 1) continue;
		sort(prime[i].begin(), prime[i].end());
		if(prime[i].size()==n)
			ans *= pow(i, prime[i][1]);
		else ans *= pow(i, prime[i][0]);
	}
	printf("%lld",ans);
	return 0;
}
