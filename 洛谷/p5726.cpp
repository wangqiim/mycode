#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n,sum=0;
	int minn=10,maxn=0;
	int a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		minn=min(minn,a);
		maxn=max(maxn,a);
		sum+=a;
	}
	sum-= minn+maxn;
	printf("%.2f",1.0*sum/(n-2));
	return 0;
}
