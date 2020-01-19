#include<iostream>
using namespace std;

int res=0;
int a[1001];

int main(){
	int n;
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){	//Å¼Êý 
			a[i]=a[i-1]+a[i/2];
		}
		else{//ÆæÊý 
			a[i] = a[i-1];
		}
	}
	cout<<a[n];
	return 0;
}
