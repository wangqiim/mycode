#include<iostream>
#include<algorithm>
using namespace std;

const int maxm = 5000;
pair<int,int> nums[maxm];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>nums[i].first>>nums[i].second;
	sort(nums,nums+m);
	int i=0,res=0;
	while(n){
		if(n<=nums[i].second){
			res+=nums[i].first*n;
			break;
		}else{
			n-=nums[i].second;
			res+=nums[i].first*nums[i].second;
			i++;
		}
	}
	cout<<res;
	return 0;
}
