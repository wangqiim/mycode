#include<cstdio>

const int maxn = 10001;
struct map{
	int a;
	int b;
	int x;
	int y;
};
map nums[maxn];

int main(){
	int n;
	int x,y;
	int res = -1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&nums[i].a,&nums[i].b,&nums[i].x,&nums[i].y);
	}
	scanf("%d %d",&x,&y);
	for(int i=n;i>=1;i--){
		if(nums[i].a<=x&&nums[i].b<=y&&(nums[i].a+nums[i].x)>=x&&(nums[i].b+nums[i].y)>=y){
			res = i;
			break;
		}
	}
	printf("%d",res);
	return 0;
} 
