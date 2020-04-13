#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 300005;
long long a[maxn];
long long b[maxn];

int main(){
	int t,n;
	long long res;
	long long minheal;
	scanf("%d",&t);
	while(t--){
		res = 0;
		minheal = 0x7fffffffffffffff;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld %lld",&a[i],&b[i]);
		for(int i=1;i<=n;i++){
			int ne;
			if(i==n) ne = 1;
			else ne = i+1;
			if(a[ne]>b[i]){
				res += a[ne]-b[i];
				a[ne] = b[i];
			}
			minheal = min(minheal,a[ne]);
		}
		printf("%lld\n",res+minheal);
	}
	return 0;
} 

