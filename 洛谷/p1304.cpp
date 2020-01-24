#include<iostream>
#include<string>
using namespace std;

int main(){
	bool prime[10001]={true,true,false};	//false��ʾ������	
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=2*i;j<=n;j=j+i){
			prime[j]=true;
		}
	}
	for(int i=4;i<=n;i=i+2){	//��������4-N
		for(int j=2;j<=n/2;j++){	//��i������ 
			if(!prime[j]&&!prime[i-j]){	//�ҵ��� 
				cout<<i<<"="<<j<<"+"<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
}
