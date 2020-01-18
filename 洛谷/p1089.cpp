#include<iostream>
using namespace std;


int main(){
	int cost;
	int remain = 0;
	int bank = 0;	//妈妈手里的钱 
	int res=0;	//0表示钱够用。 
	for(int i=0;i<12;i++){
		cin>>cost;
		remain += 300;
		remain -= cost;
		if(remain<0){	//该月不够用了 
			res = i+1;
			break;
		}else{	//该月够用 
			bank += 100*(remain/100);
			remain %= 100;
		}
	}
	if(res!=0){
		cout<<-res;
	}
	else{
		cout<<1.2*bank+remain;	//记得加上最后手里的零钱 
	}
	return 0;
}
