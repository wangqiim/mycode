#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int t,n,res;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int k = 2;
		while(n%((int)pow(2,k)-1)!=0){
			k++;
		}
		printf("%d\n",n/((int)pow(2,k)-1));
	}
	return 0;
} 
