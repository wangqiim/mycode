#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1003;
struct f_t{
	int f;
	int t;
};
f_t nums[maxn];

bool cmp(f_t a,f_t b){
	return a.f>b.f;
}

int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
		scanf("%d %d",&nums[i].f,&nums[i].t);
	sort(nums,nums+n,cmp);
	int peo = 0;
	int ans = 0;	//总需要的时间 
	while(peo<n){	//s:当前楼层 
		ans += s-nums[peo].f;
		s = nums[peo].f;	//更新当前楼层 
		ans = max(ans,nums[peo].t);
		peo++;
	}
	ans += s;
	printf("%d\n",ans);
	return 0;
}
