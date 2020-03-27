#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200005;

int nums[maxn];
int color[maxn];

int main(){
	int q,n,t;
	int ans;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
		}
		color[0] = 1;	//1,2,3   3种颜色
		ans = 1;
		int change = -1;
		for(int i=1;i<n-1;i++){
			if(nums[i]==nums[i-1]){
				color[i] = color[i-1];
				change = i;
			}
			else{
				color[i] = 3 - color[i-1];
				ans = 2;
			}
		}
		if(nums[n-1]!=nums[0]&&nums[n-1]!=nums[n-2]){	//最后一个数和两边都不相同
			if(color[n-2]==color[0]){	//两边颜色相同时 
				color[n-1] = 3 - color[0];
			}else{
				if(change==-1){
					color[n-1] = 3;
				}else{
					for(int i = change;i<n-1;i++){
						color[i] = 3 - color[i];	//换色 
					}
					color[n-1] = 3 - color[0];
				}
			}
		}else if(nums[n-1]==nums[0]&&nums[n-1]==nums[n-2]){
			color[n-1] = color[0];
		}else if(nums[n-1]==nums[0]){
			color[n-1] = 3-color[n-2];
		}else{
			color[n-1] = 3-color[0];
		}
		printf("%d\n",max(ans,color[n-1]));
		for(int i=0;i<n;i++){
			printf("%d ",color[i]);
		}
		printf("\n");
	}
	return 0;
}
