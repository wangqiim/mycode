#include<iostream>
using namespace std;


int main(){
	int cost;
	int remain = 0;
	int bank = 0;	//���������Ǯ 
	int res=0;	//0��ʾǮ���á� 
	for(int i=0;i<12;i++){
		cin>>cost;
		remain += 300;
		remain -= cost;
		if(remain<0){	//���²������� 
			res = i+1;
			break;
		}else{	//���¹��� 
			bank += 100*(remain/100);
			remain %= 100;
		}
	}
	if(res!=0){
		cout<<-res;
	}
	else{
		cout<<1.2*bank+remain;	//�ǵü�������������Ǯ 
	}
	return 0;
}
