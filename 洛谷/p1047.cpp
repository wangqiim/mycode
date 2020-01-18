#include<iostream>
using namespace std;

int road[10001];

int main(){
	int i,j,res=0;
	int L,M;
	int begin,end;
	cin>>L>>M;
	for(i=0;i<=L;i++)
		road[i]=1;	//³õÊ¼»¯ 
	for(i=0;i<M;i++){
		cin>>begin>>end;
		for(j=begin;j<=end;j++)
			road[j]=0;
	}
	for(i=0;i<=L;i++)
		res+=road[i];
	cout<<res;
	return 0;
}
