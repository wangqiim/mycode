#include<iostream>
#include<vector>
using namespace std;

int main(){//也可以用动态规划
	int n,m,t;	 
	cin>>n>>m;
	if(n>=m){
		cout<<"YES";
		return 0;
	}
	vector<bool> nums0(m,false);
	vector<bool> nums(m,false);	//nums[i]=true表示存在取余是i的子序列和
	nums0[0] = true;
	nums[0] = true;
	for(int i=0;i<n;i++){
		cin>>t;
		for(int j=0;j<m;j++){
			if(nums0[j]){
				if((t+j)%m==0){
					cout<<"YES";
					return 0;
				}else{
					nums[(t+j)%m]=true;
				}
			}
		}
		nums0.assign(nums.begin(),nums.end());
	}
	cout<<"NO";
	return 0;
}