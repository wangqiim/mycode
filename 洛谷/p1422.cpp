#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int a;
	double res;
	cin>>a;
	if(a<=150){
		res=0.4463*a;
	}else if(a<=400){
		res=150*0.4463+(a-150)*0.4663;
	}else{
		res=150*0.4463+(400-150)*0.4663+(a-400)*0.5663;
	}
	cout<<int(res*10+0.5)/10.0;
}
