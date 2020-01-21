#include<iostream>
#include<cmath>
using namespace std;

int a[20];
int n,k,res=0;

bool isprime(int n){	//判质数 
	if(n==1)
		return false;
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;
}

void myfunc(int nown,int begin,int s){	//nown为已选的个数,begin为目前是否选第begin个,s为begin之前的和。
	if(nown == k){	//够了。 
		if(isprime(s))
			res++;
		return;
	}
	else{	//不够 
		if(begin<n){
			myfunc(nown+1,begin+1,s+a[begin]);	//选第begin个数
			myfunc(nown,begin+1,s);	//不选第begin个数
			return;
		}
		else{
			return;
		}
	}
}//可以进行剪枝，直接AC了就不加了 

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	myfunc(0,0,0);
	cout<<res;
	return 0;
}
