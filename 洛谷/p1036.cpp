#include<iostream>
#include<cmath>
using namespace std;

int a[20];
int n,k,res=0;

bool isprime(int n){	//������ 
	if(n==1)
		return false;
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;
}

void myfunc(int nown,int begin,int s){	//nownΪ��ѡ�ĸ���,beginΪĿǰ�Ƿ�ѡ��begin��,sΪbegin֮ǰ�ĺ͡�
	if(nown == k){	//���ˡ� 
		if(isprime(s))
			res++;
		return;
	}
	else{	//���� 
		if(begin<n){
			myfunc(nown+1,begin+1,s+a[begin]);	//ѡ��begin����
			myfunc(nown,begin+1,s);	//��ѡ��begin����
			return;
		}
		else{
			return;
		}
	}
}//���Խ��м�֦��ֱ��AC�˾Ͳ����� 

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	myfunc(0,0,0);
	cout<<res;
	return 0;
}
