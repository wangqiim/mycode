#include<iostream>
using namespace std;

//д�������ݹ��㷨����ΪҪ���������������Ȱѽ���ݴ�Ļ�Ҫ�����顣��С�Ļ��� 
int a[10];
int res=0;

void myfunc(int no,int remain){	//no��ǰ��������ϣ�remain����Ҫ������ 
	if(no==10){
		if(remain==0){	//���� 
			res++;
		}
	}else{
		for(int i=1;i<=3;i++){
			a[no]=i;
			myfunc(no+1,remain-i);
		} 
	}
	return;
} 

void myfunc2(int no,int remain){	//no��ǰ��������ϣ�remain����Ҫ������ 
	if(no==10){
		if(remain==0){	//���� 
			for(int i=0;i<10;i++){
				cout<<a[i];
				if(i==9)
					cout<<endl;
				else
					cout<<" ";
			}
		}
	}else{
		for(int i=1;i<=3;i++){
			a[no]=i;
			myfunc2(no+1,remain-i);
		} 
	}
	return;
} 

int main(){
	int n;
	cin>>n;
	myfunc(0,n); 
	cout<<res<<endl;
	myfunc2(0,n);
	return 0;
}
