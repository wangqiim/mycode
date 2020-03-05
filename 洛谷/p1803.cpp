#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000000;
pair<int,int> nums[maxn];	//fisrt为结束时间，second为开始时间 

int main(){
	int n,res=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>nums[i].second>>nums[i].first;
	sort(nums,nums+n);
	for(int i=0,now=0;i<n;i++){
		if(nums[i].second>=now){
			now = nums[i].first;
			res++;	
		}
	}
	cout<<res;
	return 0;	
}
