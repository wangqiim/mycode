#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b > b+a;
}

int main(){
	int n;
	string res="";
	cin>>n;
	vector<string> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	sort(nums.begin(),nums.end(),cmp);
	for(int i=0;i<n;i++)
		res+=nums[i];
	cout<<res;
	return 0;
}
