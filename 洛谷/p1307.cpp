#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){	//此题考虑到整数的范围较小,也可以直接利用int接收处理 
	string nums,res="";
	int size,i;
	cin>>nums;
	size = nums.size();
	if(nums[0]=='-'){
		reverse(nums.begin()+1,nums.end());
		for(i=1;i<size;i++){
			if(nums[i]!='0')
				break;
		}
		res = "-"+nums.substr(i);
	}else{
		reverse(nums.begin(),nums.end());
		for(i=0;i<size;i++){
			if(nums[i]!='0')
				break;
		}
		res = nums.substr(i);
	}
	cout<<res;
	return 0;
}
