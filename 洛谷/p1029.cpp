#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
int gcd(ll a,ll b){
	if(b==0)
		return a;
	else return gcd(b,a%b);	
}

int main(){
	ll x,y;
	scanf("%lld %lld",&x,&y);
	ll s = x*y;
	ll n = sqrt(s);
	//原来两数的乘积就是最小公倍数的乘积 
	int res = 0;
	int flag = 0;	//判断是否有相同的两个数字 
	for(int i=1;i<=n;i++)
		if(s%i==0&&gcd(s/i,i)==x){
			res++;
			if(s/i==i)
				flag = 1;
		}
	printf("%d",res*2-flag);
	return 0;
}
