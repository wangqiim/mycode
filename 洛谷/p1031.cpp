#include<iostream>
using namespace std;

const int maxn = 10000;
int nums[maxn];

int main(){
	int n,sum=0,res=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nums[i];
		sum+=nums[i];
	}
	sum/=n;
	for(int i=0;i<n-1;i++){
		if(nums[i]!=sum){
			nums[i+1]+=nums[i]-sum;
			res++;//��i�Ѳ���,��Ҫ�����ڵ�i+1�� 
		}
	}
	cout<<res;
	return 0;
}
