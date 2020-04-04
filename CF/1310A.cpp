#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 200005;
pair<int,int> nums[maxn];
priority_queue<int> pq;


int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&nums[i].first);
	for(int i=0;i<n;i++) scanf("%d",&nums[i].second);
	sort(nums,nums+n);
	int now = nums[0].first;
	pq.push(nums[0].second);
	long long res = 0;
	long long sum = nums[0].second;	//当前优先队列元素(t)和 
	for(int i=1;i<=n;i++){
		if(nums[i].first>now)
			if(pq.empty())
				now = nums[i].first;
			else
				while(!pq.empty()&&nums[i].first>now){
					sum -= pq.top();
					res += sum;
					pq.pop();
					now++;
				}
		pq.push(nums[i].second);
		sum += nums[i].second;
		now = nums[i].first;
	}
	while(!pq.empty()){
		sum -= pq.top();
		res += sum;
		pq.pop();
	} 
	printf("%lld",res); 
	return 0;	
}
