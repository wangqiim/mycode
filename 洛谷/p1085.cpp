#include<iostream>
using namespace std;

int main(){
	int a[7][2];
	int i,j,t;
	int maxn=0,index=0;
	for(i = 0;i<7;i++){
		for(j = 0;j<2;j++){
			cin>>a[i][j];
		}
		t = a[i][0]+a[i][1];
		if(t>maxn&&t>8){
			index = i+1;
			maxn = t;
		}
	}
	cout<<index;
	return 0;
} 
