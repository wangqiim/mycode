#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1003;
int nums[maxn];
int res_nums[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&nums[i]);
	long long res = 0;	//最大值 
	int max_i = 0;	//最大值时山峰出现的位置 
	long long sum;
	int up_bound;	//上界 
	for(int i=0;i<n;i++){
		sum = nums[i];
		up_bound = nums[i];
		for(int j=i-1;j>=0;j--){
			up_bound = min(nums[j],up_bound);
			sum += up_bound;
		}
		up_bound = nums[i];
		for(int j=i+1;j<n;j++){
			up_bound = min(nums[j],up_bound);
			sum += up_bound;
		}
		if(sum>res){
			res = sum;
			max_i = i;
		}
	}
	up_bound = nums[max_i];
	res_nums[max_i] = nums[max_i];
	for(int j=max_i-1;j>=0;j--){
		up_bound = min(up_bound,nums[j]);
		res_nums[j] = up_bound;
	}
	up_bound = nums[max_i];
	for(int j=max_i+1;j<n;j++){
		up_bound = min(up_bound,nums[j]);
		res_nums[j] = up_bound;
	}
	for(int i=0;i<n;i++)
		printf("%d ",res_nums[i]);
	return 0;
}
