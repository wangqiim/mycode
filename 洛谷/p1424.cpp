#include<iostream>
using namespace std;

int main(){
	int x,n,res=0;
	cin>>x>>n;
	res += (n/7)*250*5;	//ÿ7��һ������,��������ͬ�� 
	n = n%7;
	for(;n>0;n--){
		if(x!=6&&x!=7)
			res += 250;
		x = x%7+1;	//��ֹ����7��ÿ��ȡģ�ټ�1 
	}
	cout<<res;
	return 0;
}
