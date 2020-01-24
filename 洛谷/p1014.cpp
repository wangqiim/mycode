#include<iostream>
using namespace std;

int main(){
	int n,i,s;
	int fx=-1; //1表示从右上角到左下角,-1反之 
	cin>>n;
	for(i=1,s=0;;i++){	//每斜行有i个数
		if(s+i>=n)	//第i斜行出现了第n个 
			break;
		s+=i;
		fx = -fx;
	}
	if(fx==1){
		cout<<(n-s)<<"/"<<i+1-(n-s);
	}else{
		cout<<i+1-(n-s)	<<"/"<<(n-s);
	}
	return 0;
}
