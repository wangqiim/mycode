#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500005;
long long nums[maxn];
int stack[maxn];	//单调栈,存索引 
int len;
int left_lo[maxn];	//left_lo[i]:左边第一个比i小的索引
int right_lo[maxn];	//right_lo[i]:右边第一个比i小的索引 
long long left_sum[maxn];
long long right_sum[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&nums[i]);
	len = 0;
	for(int i=1;i<=n;i++){	//right_lo
		while(len!=0&&nums[i]<nums[stack[len-1]]){
			right_lo[stack[len-1]] = i;
			len--;
		}
		stack[len++] = i;
	}
	len = 0;
	for(int i=n;i>0;i--){ //left_lo
		while(len!=0&&nums[i]<nums[stack[len-1]]){
			left_lo[stack[len-1]] = i;
			len--;
		}
		stack[len++] = i;
	}
	for(int i=1;i<=n;i++){	//计算 left_sum
		if(left_lo[i]==0)
			left_sum[i] = i*nums[i];
		else
			left_sum[i] = left_sum[left_lo[i]] + (i-left_lo[i])*nums[i];
	}
	for(int i=n;i>0;i--){	//计算 right_sum
		if(right_lo[i]==0)
			right_sum[i] = (n-i+1)*nums[i];
		else
			right_sum[i] = right_sum[right_lo[i]] + (right_lo[i]-i)*nums[i];
	}
	long long res = 0;
	long long index = 1;
	for(int i=1;i<=n;i++){
		long long sum = left_sum[i]+right_sum[i]-nums[i];
		if(sum>res){
			res = sum;
			index = i;
		}
	}
	long long up_bound = nums[index];
	for(int i=index-1;i>0;i--){
		up_bound = min(up_bound,nums[i]);
		nums[i] = up_bound;
	}
	up_bound = nums[index];
	for(int i=index+1;i<=n;i++){
		up_bound = min(up_bound,nums[i]);
		nums[i] = up_bound;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",nums[i]);
	}
	return 0;
}
