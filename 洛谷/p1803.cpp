#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000000;
pair<int,int> nums[maxn];	//fisrtΪ����ʱ�䣬secondΪ��ʼʱ�� 

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
