#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 300005;
int nums[maxn];
int res[maxn];

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&nums[i]);
		sort(nums,nums+n);
		int L=0,R=n-1;
		int index = 0;
		while(1){
			if(index>=n) break;
			res[index++] = nums[L++];
			if(index>=n) break;
			res[index++] = nums[R--];
		}
		for(int i=n-1;i>=0;i--){
			printf("%d ",res[i]);
		}putchar('\n');
	}
	return 0;
}
