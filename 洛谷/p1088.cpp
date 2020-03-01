#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10000;
int nums[maxn];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&nums[i]);
	while(m--)
		next_permutation(nums,nums+n);
	for(int i=0;i<n;i++)
		printf("%d ",nums[i]);
	return 0;
}
