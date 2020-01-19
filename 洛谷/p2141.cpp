#include<iostream>
using namespace std;

int main(){
	int n,i,j,k,flag,res=0;
	int a[100];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		flag = 0;
		for(j = 0;j<n-1;j++){
			if(j==i)
				continue;
			for(k = j+1;k<n;k++){
				if(k==i)
					continue;
				if(a[j]+a[k]==a[i]){
					res++;
					flag = 1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	cout<<res;
	return 0;
}
