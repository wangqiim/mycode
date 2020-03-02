#include<iostream> 
#include<string>
using namespace std;

const int maxn = 100000;
struct people{
	int face;	//0朝圈内 
	string job;	
};

people nums[maxn];

int main(){
	int n,m;//人数，指令数
	int res = 0;	//从第一个读入的小人开始 
	int a,s;	//a=0左数,a=1右数.第s个人. 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nums[i].face>>nums[i].job;
	}
	for(int i=0;i<m;i++){
		cin>>a>>s;	//输入保证1<=s<=n 
		if(nums[res].face^a==1){//朝内右手 或者朝外左手 
			res = (res+s)%n;
		}
		else{
			res = (n+res-s)%n;
		} 
	}
	cout<<nums[res].job;
	return 0;
}
