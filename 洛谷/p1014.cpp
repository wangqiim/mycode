#include<iostream>
using namespace std;

int main(){
	int n,i,s;
	int fx=-1; //1��ʾ�����Ͻǵ����½�,-1��֮ 
	cin>>n;
	for(i=1,s=0;;i++){	//ÿб����i����
		if(s+i>=n)	//��iб�г����˵�n�� 
			break;
		s+=i;
		fx = -fx;
	}
	if(fx==1){
		cout<<(n-s)<<"/"<<i+1-(n-s);
	}else{
		cout<<i+1-(n-s)	<<"/"<<(n-s);
	}
	return 0;
}
