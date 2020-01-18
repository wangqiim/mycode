#include<iostream>
using namespace std;

int main(){
	double m,s=0,i=0,step=2;
	cin>>m;
	while(s<=m){
		s += step;
		step *= 0.98;
		i++;
	}
	cout<<i;
	return 0;
}
