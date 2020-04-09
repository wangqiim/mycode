#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 3003;
char nums[maxn];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",nums);
	vector<vector<int> > ans=vector<vector<int> >(k,vector<int>());
	int tot=0,cnt=0;	//tot为总转向次数，cnt为最少转向轮数 
	while(1){
		vector<int> tnums;
		for(int i=0;i<n-1;i++){
			if(nums[i]=='R'&&nums[i+1]=='L'){
				tnums.push_back(i);
				tot++;	//转身的次数 
			}
		}
		int sizet = tnums.size();
		if(sizet==0) break;	//已经没有需要转向的了
		ans.push_back(tnums);
		if(cnt==k){
			printf("-1\n");
			return 0;
		}
		ans[cnt++] = tnums;
		for(int i=0;i<sizet;i++) swap(nums[tnums[i]],nums[tnums[i]+1]);
	}
	if(k<cnt||k>tot){
		printf("-1\n");
	}else{
		int now_cnt = cnt-1;
		for(int i=k-1;i>=0;i--){
			if(ans[now_cnt].empty()) now_cnt--;
			if(now_cnt==i) break;
			ans[i] = vector<int>{ans[now_cnt].back()};
			ans[now_cnt].pop_back();
		}
		for(int i=0;i<k;i++){
			printf("%d",ans[i].size());
			for(auto x:ans[i])
				printf(" %d",x+1);
			putchar('\n');
		}
	}
	return 0;
}
