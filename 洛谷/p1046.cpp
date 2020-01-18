#include<iostream>
using namespace std;

int main(){
	int n[10],height,res=0;
	for(int i=0;i<10;i++){
		cin>>n[i];
	}
	cin>>height;
	height += 30;
	for(int i=0;i<10;i++){
		if(height>=n[i])
			res++;
	} 
	cout<<res;
	return 0;
}
