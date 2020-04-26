#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int t;
	long long x,y,a,b;
	scanf("%d",&t);
	long long ans1,ans2,res;
	while(t--){
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		ans1 = a*(abs(x)+abs(y));
		if(x*y<0)
			ans2 = ans1;
		else
			ans2 = b*min(abs(x),abs(y)) + a*(max(abs(x),abs(y))-min(abs(x),abs(y)));
		res = min(ans1,ans2);
		printf("%lld\n",res);
	}
	return 0;
}
