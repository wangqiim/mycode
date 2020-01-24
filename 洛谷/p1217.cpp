#include<iostream>
using namespace std;
//根据数学性质偶数回文数不可能质数。
//因此数组可以少开一点 
bool isprime[10000000]={true,true,false};// 0 1 2false表示是质数

bool ishuiwen(int n){
	int newn=0,oldn=n;
	while(n!=0){
		newn = newn*10+n%10;
		n /= 10;
	}
	if(newn==oldn)
		return true;
	else 
		return false;
}

int main(){
	int a,b;
	cin>>a>>b;
	if(b>9999999)	
	    b = 9999999;
	for(int i=2;i<=b;i++){
		if(isprime[i])
			continue;
		else{
			for(int j=2*i;j<=b;j=j+i){
				isprime[j]=true;
			}
		}
	}
	for(int i=a;i<=b;i++){
		if(!isprime[i]&&ishuiwen(i))
			cout<<i<<endl;
	}
	return 0;
}
