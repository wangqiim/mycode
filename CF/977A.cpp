#include<iostream>

using namespace std;

const int maxn = 1e9;
const int maxk = 50;
int n;
int k;

int main(){
	cin>>n>>k;
	while(k!=0){
		if(n%10!=0){
			n--;
		}
		else{
			n /= 10; 
		}
		k--;
	}
	cout<<n;
	return 0;
} 
