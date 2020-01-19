#include<iostream>
using namespace std;

int main(){
	int n;
	int t=1,res=0;
	int yesterday=-1,today;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>today;
		if(today>yesterday)
			t++;
		else{
			res = t>res?t:res;
			t=1;
		}
		yesterday = today;
	}
	cout<<res;
	return 0;
}
