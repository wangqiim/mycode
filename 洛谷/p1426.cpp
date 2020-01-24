#include<iostream>
using namespace std;

int main(){
	double s,x,l=0;
	double v=7;
	int flag;
	cin>>s>>x;
	double begin=s-x;
	double end=s+x;
	if(begin>=350){	//距离会收敛到350,先判断防止后续死循环 
		cout<<"n";
		return 0;
	}
	if(l>=begin&&l<=end)
		flag=1;
	else
		flag=0; 
	for(int i=0;l<end;i++){
		l += v;
		if(l>=begin&&l<=end){	//该回合被扫描到了 
			if(flag == 0)	//上回合没被扫描到 
				flag = 1;
			else{	//上回合被扫描到了 
				cout<<"y";	//捕捉 
				return 0;
			}
		}
		v *= 0.98;
	}
	cout<<"n";
	return 0;
} 
