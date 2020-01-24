#include<iostream>
using namespace std;

int main(){
	int n,res=0;
	int a[10000],b[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>n;
	a[0] = 6;
	for(int i=1;i<4000;i++){
		int j=i;
		a[i] = 0;
		while(j!=0){
			a[i] += b[j%10];
			j /= 10;
		}
	}
	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			if(a[i]+a[j]+a[i+j]+4==n){
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}
