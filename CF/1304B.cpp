#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 102;
bool use[maxn];
string nums[maxn]; 

bool ispalindrome(string s){
	int n = s.size();
	bool res = true;
	for(int i=0;i<n;i++)
		if(s[i]!=s[n-i-1]){
			res = false;
			break;
		}
	return res;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>nums[i];
	string res_left;
	string res_right;
	int res = 0;
	for(int i=0;i<n;i++){
		if(use[i]) continue;
		reverse(nums[i].begin(),nums[i].end());
		for(int j=0;j<n;j++){
			if(j==i||use[j]) continue;
			if(nums[i]==nums[j]){
				res_left += nums[j];
				res_right+= nums[i];
				use[i] = use[j] = true;
				res += m*2;
				break;
			}
		}
		reverse(nums[i].begin(),nums[i].end());
	}
	for(int i=0;i<n;i++){
		if(!use[i]&&ispalindrome(nums[i])){
			res_left += nums[i];
			res+=m;
			break;
		}
	}
	reverse(res_right.begin(),res_right.end());
	cout<<res<<endl;
	cout<<res_left+res_right<<endl;
	return 0;
}
