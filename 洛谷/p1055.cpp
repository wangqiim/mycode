#include<iostream>
using namespace std;

int main(){
	char m[14],n[11];
	int res=0;	//�ۼӽ�� 
	char t;	
	for(int i=1,j = 1;i<=13;i++){//����浽n[1]-n[10]�� 
		cin>>m[i];
		if(m[i]!='-'){
			n[j] = m[i];
			j++;
		} 
	}
	for(int i = 1;i<=9;i++){//�ۼ� 
		res += (n[i]-'0')*i;
	}
	res %= 11;//ȡģ 
	if(res==10)
		t = 'X';
	else t = (char)(res+'0');	//�õ���ȷ��ʶ���� 
	if(t==n[10])
		cout<<"Right";
	else{
		for(int i = 1;i<=12;i++){
			cout<<m[i];
		}
		cout<<t;

	}
	return 0;
} 
