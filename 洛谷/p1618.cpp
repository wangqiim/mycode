#include<iostream>
using namespace std;


int main(){
	int n[3];	//���� 
	int A,B,C;
	int flag1,flag2=0;	//flag1�ж��ǲ�������1-9���õ���flag2�ж���û�н�� 
	bool number[10];	//false��ʾ�������û��
	cin>>n[0]>>n[1]>>n[2];
	for(int i=0;i<2;i++){	//��С��������a,b,c 
		for(int j=2;j>i;j--){
			if(n[j]<n[j-1]){
				int t =n[j];
				n[j] = n[j-1];
				n[j-1] = t;
			}
		}
	}
	for(int i=1;;i++){
		flag1 = 0;
		A = i * n[0];
		B = i * n[1];
		C = i * n[2];
		if(C>999)
			break;
		while(A>0){
			number[A%10] = true;
			A /=10;
		}
		while(B>0){
			number[B%10] = true;
			B /=10;
		}
		while(C>0){
			number[C%10] = true;
			C /=10;
		}
		for(int i=1;i<10;i++){
			if(!number[i]){	//��û�õ�����false 
				flag1 = 1;
				break;
			}
		}
		for(int i=1;i<10;i++)
			number[i]=false;	//��ʼ�� number���� 
		if(flag1 == 0){
			flag2=1;
			cout<<i * n[0]<<" "<<i * n[1]<<" "<<i * n[2]<<endl;
		}	
	}
	if(flag2 == 0)
		cout<<"No!!!";
	return 0;
}
