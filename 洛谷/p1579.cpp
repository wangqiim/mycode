#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n){
	if(n<=1)
		return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	for(int i=2;i<n;i++){
		if(prime(i))
			for(int j=i;j<n;j++){
				if(prime(j)&&prime(n-i-j)){
					cout<<i<<" "<<j<<" "<<n-i-j;
					return 0;
				}
			}
	}
	return 0;
}
