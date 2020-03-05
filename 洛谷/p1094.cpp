#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 30000;
int nums[maxn];

int main(){
	int w,n;	//价格和不超过w,n件物品 
	cin>>w>>n;
	for(int i=0;i<n;i++)
		cin>>nums[i];
	sort(nums,nums+n);
	int l=0,r=n-1;
	int res = 0;
	while(l<=r){
		res++;
		if(l==r) break;
		if(nums[l]+nums[r]<=w)
			l++;
		r--;
	}
	cout<<res;
	return 0;	
}
