#include<iostream>
using namespace std;

int main(){
	int n,x,t,res=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		t = i;
		while(t!=0){
			if(t%10==x)
				res++;
			t /= 10;
		}
	}
	cout<<res;
	return 0;
}
