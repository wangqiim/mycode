#include<iostream>
using namespace std;

int main(){
	double s,x,l=0;
	double v=7;
	int flag;
	cin>>s>>x;
	double begin=s-x;
	double end=s+x;
	if(begin>=350){	//�����������350,���жϷ�ֹ������ѭ�� 
		cout<<"n";
		return 0;
	}
	if(l>=begin&&l<=end)
		flag=1;
	else
		flag=0; 
	for(int i=0;l<end;i++){
		l += v;
		if(l>=begin&&l<=end){	//�ûغϱ�ɨ�赽�� 
			if(flag == 0)	//�ϻغ�û��ɨ�赽 
				flag = 1;
			else{	//�ϻغϱ�ɨ�赽�� 
				cout<<"y";	//��׽ 
				return 0;
			}
		}
		v *= 0.98;
	}
	cout<<"n";
	return 0;
} 
