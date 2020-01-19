#include<iostream>
using namespace std;

int main(){
	int n,i,j;
	int fish[100];
	int res[100];	//也可以从后向前遍历，则只需要一个数组。 
	cin>>n;
	for(i=0;i<n;i++){
		cin>>fish[i];
		res[i]=0;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(fish[j]<fish[i])
				res[i]++;
		}
	}
	for(i=0;i<n;i++){
		cout<<res[i]<<" ";
	}
	return 0;
} 
