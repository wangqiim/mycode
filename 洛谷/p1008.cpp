#include<iostream>
using namespace std;

int main(){
	int i,a,b,c;
	int n[10];

	for(a=123;a<=333;a++){
		b = 2*a;
		c = 3*a;
		for(i = 1; i<10 ; i++)
			n[i] = 0;
		n[a/100]=n[a/10%10]=n[a%10]=n[b/100]=n[b/10%10]=n[b%10]=n[c/100]=n[c/10%10]=n[c%10]=1;
		for(i = 1; i<10 ; i++)
			if(n[i]==0)
				break;
		if(i==10)
			cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
