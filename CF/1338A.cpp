#include<cstdio>
#include<algorithm>
using namespace std;

int mypow[31];

int main(){
	int t,n;
	mypow[0]=1;
	int sum = 1;
	for(int i=1;i<=30;i++){
		sum*=2;
		mypow[i] = mypow[i-1]+sum;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int maxval = -1000000009;
		int d = 0;
		int a;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			d = max(d,maxval-a);
			maxval = max(maxval,a);
		}
		if(d<=0){
			puts("0");
		}else{
			int res = 0;
			for(int i=0;i<=30;i++){
				if(mypow[i]>=d){
					res = i;
					break;
				}
			}
			printf("%d\n",res+1);
		}
	}
	return 0;
}
