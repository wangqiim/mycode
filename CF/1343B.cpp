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
		if((n/2)%2==1)
			puts("NO");
		else{
			puts("YES");
			int cnt = n/2;
			for(int i=2;i<=n;i+=2)
				printf("%d ",i);
			for(int i=1;i<=n-2;i+=2)
				printf("%d ",i);
			printf("%d\n",(n/2-1)+n);
		}
	}
	return 0;
} 
