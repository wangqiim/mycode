#include<iostream>
using namespace std;

int main(){
	int x,n,res=0;
	cin>>x>>n;
	res += (n/7)*250*5;	//每7天一个周期,增长量相同。 
	n = n%7;
	for(;n>0;n--){
		if(x!=6&&x!=7)
			res += 250;
		x = x%7+1;	//防止超过7，每次取模再加1 
	}
	cout<<res;
	return 0;
}
