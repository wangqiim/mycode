#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200005;

char a[maxn];
char b[maxn];
int b_ones[maxn];	// b数组,前缀中1的个数 
int b_zeros[maxn];

int main(){
	scanf("%s %s",a,b);	//|a|<=|b|
	long long ans = 0;
	int m = strlen(a),n = strlen(b);
	b_ones[0] = b[0]-'0';
	b_zeros[0] = 1-(b[0]-'0');
	for(int i=1;i<n;i++){
		b_ones[i] = b_ones[i-1]+b[i]-'0';
		b_zeros[i] = b_zeros[i-1]+1-(b[i]-'0');
	}
	if(a[0]=='0')
		ans += b_ones[n-m];
	else
		ans += b_zeros[n-m];
	for(int i=1;i<m;i++)
		if(a[i]=='0')
			ans += b_ones[n-m+i]-b_ones[i-1];
		else
			ans += b_zeros[n-m+i]-b_zeros[i-1];
	printf("%lld\n",ans);
	return 0;
}
