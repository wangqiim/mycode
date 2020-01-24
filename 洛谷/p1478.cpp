#include<iostream>
#include<algorithm>
using namespace std;

struct apple{
	int x;
	int y;
};

bool cmp(apple a,apple b){
	return a.y<b.y;
}

int main(){
	int n,s,a,b;
	int res=0;
	apple nums[5000];
	cin>>n>>s>>a>>b;
	for(int i=0;i<n;i++){
		cin>>nums[i].x>>nums[i].y;
	}
	sort(nums,nums+n,cmp);
	for(int i=0;i<n;i++){
		if(s<nums[i].y)
			break;
		else if(nums[i].x<=(a+b)){
			res++;
			s -= nums[i].y;
		}
	}
	cout<<res;
	return 0;
} 
