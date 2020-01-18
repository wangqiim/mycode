#include<iostream>
using namespace std;

int main(){
	int n,k;
	double i,s=0;
	cin>>k;
	for(i = 1;;i++){
		s+=1/i;
		if(s>k)
			break;
	}
	cout<<i;
	return 0;
}
