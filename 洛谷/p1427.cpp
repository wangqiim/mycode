#include<iostream>
using namespace std;

int main(){
	int n[101];
	int i;
	for(i = 0;i<100;i++){
		cin>>n[i];
		if(n[i]==0)
			break;
	} 
	for(i--;i>=0;i--){
		cout<<n[i]<<" ";
	}
	return 0;
}  
