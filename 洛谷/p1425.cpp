#include<iostream>
using namespace std;


int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d-b>=0){
		cout<<c-a<<" "<<d-b;
	}
	else{
		cout<<c-a-1<<" "<<d-b+60;
	}
	return 0; 
} 