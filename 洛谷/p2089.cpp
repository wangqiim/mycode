#include<iostream>
using namespace std;

//写了两个递归算法，因为要先输出个数。如果先把结果暂存的话要开数组。大小的话？ 
int a[10];
int res=0;

void myfunc(int no,int remain){	//no当前处理的配料，remain还需要的数量 
	if(no==10){
		if(remain==0){	//够了 
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

void myfunc2(int no,int remain){	//no当前处理的配料，remain还需要的数量 
	if(no==10){
		if(remain==0){	//够了 
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
