#include<iostream>
using namespace std;


int main(){
	int n[3];	//输入 
	int A,B,C;
	int flag1,flag2=0;	//flag1判断是不是所有1-9都用到，flag2判断有没有结果 
	bool number[10];	//false表示这个数还没用
	cin>>n[0]>>n[1]>>n[2];
	for(int i=0;i<2;i++){	//从小到达排序a,b,c 
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
			if(!number[i]){	//有没用到的数false 
				flag1 = 1;
				break;
			}
		}
		for(int i=1;i<10;i++)
			number[i]=false;	//初始化 number数组 
		if(flag1 == 0){
			flag2=1;
			cout<<i * n[0]<<" "<<i * n[1]<<" "<<i * n[2]<<endl;
		}	
	}
	if(flag2 == 0)
		cout<<"No!!!";
	return 0;
}
