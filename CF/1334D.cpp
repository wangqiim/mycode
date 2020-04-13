#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;
long long acc[maxn];
int t,n;
long long l,r;

int solve(long long x){
	if(x==acc[n]) return 1;
	int left = 1,right = n;
	while(left<right){
		int mid = (left+right)/2;
		if(acc[mid]>=x) right = mid;
		else left = mid+1;
	}
	int ind = x - acc[left-1];
	if(ind%2==1) return left;
	else return left+ind/2;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld %lld",&n,&l,&r);
		for(int i=1;i<n;i++)
			acc[i] = acc[i-1]+(n-i)*2;
		acc[n] = acc[n-1]+1;
		for(long long i=l;i<=r;i++)
			printf("%d ",solve(i));
		putchar('\n');
	}
	return 0;
} 

