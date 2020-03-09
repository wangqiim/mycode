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
	//ԭ�������ĳ˻�������С�������ĳ˻� 
	int res = 0;
	int flag = 0;	//�ж��Ƿ�����ͬ���������� 
	for(int i=1;i<=n;i++)
		if(s%i==0&&gcd(s/i,i)==x){
			res++;
			if(s/i==i)
				flag = 1;
		}
	printf("%d",res*2-flag);
	return 0;
}
