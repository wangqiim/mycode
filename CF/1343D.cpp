#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 200005;
const int maxm = 200005;

int t,n,k,a[maxn];
int mx[maxn],mn[maxn],pp[maxn*2];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		fill(mx,mx+k+1,0);
		fill(mn,mn+k+1,0);
		fill(pp,pp+2*k+1,0);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n/2;i++){
			int x=a[i]+a[n-1-i];
			mx[max(a[i],a[n-1-i])]++;
			mn[min(a[i],a[n-1-i])]++;
			pp[x]++;
		}
		for(int i=1;i<=k;i++){
			mn[i] += mn[i-1];
			mx[i] += mx[i-1];
		}
		int res=n/2;	//最多动n/2个
		for(int i=2;i<=2*k;i++){
			int temp = 0;
			if(i>k+1) temp += mx[i-k-1]*2;
			if(i<=k) temp += (mn[k]-mn[i-1])*2;
			int t=n-temp;
			temp += (t/2);
			temp -= pp[i];
			res = min(temp,res);
		}
		printf("%d\n",res);
	}
	return 0;
}
