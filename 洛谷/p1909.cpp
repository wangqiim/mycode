#include<iostream>
using namespace std;

int main(){
	int n;
	int number,price,res=0x7fffffff;
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>number>>price;
		if(n%number==0){
			res=(n/number)*price>res?res:(n/number)*price;
		}
		else{
			res=(n/number+1)*price>res?res:(n/number+1)*price;
		}
	}
	cout<<res;
}
