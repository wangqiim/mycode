#include<iostream>
#include<string>
using namespace std;

//һ��������7��,���ϵ���,���������� 
int nums[11][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};

int main(){
	int k;
	string s;
	string res;
	cin>>k>>s;
	int size = s.size();
	//ÿ�����ֳַ�����.
	res = "";
	for(int i=0;i<size;i++){	//��һ�� 
		if(i!=0) res+=" ";//���˵�һ������,�����Ķ�Ҫ��ӿո�
		int number = s[i]-'0';	//�ַ�תint 
		int n=k;	 
		res+=" ";
		if(nums[number][0]==1)
			for(int j=0;j<k;j++) res+="-";//ÿһ�ʻ�Ҫ�ظ�k��
		else
			for(int j=0;j<k;j++) res+=" ";//ÿһ�ʻ�Ҫ�ظ�k��	
		res+=" ";
	}
	cout<<res<<endl;//��һ�н���
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";
		int number = s[i]-'0';
		if(nums[number][1]==1)
			res+="|";
		else
			res+=" ";
		for(int j=0;j<k;j++) res+=" ";
		if(nums[number][2]==1)
			res+="|";
		else
			res+=" ";
	}
	for(int i=0;i<k;i++){	//�ڶ���Ҫ�ظ����k�� 
		cout<<res<<endl;
	}//�ڶ��н���
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";//���˵�һ������,�����Ķ�Ҫ��ӿո�
		int number = s[i]-'0';	//�ַ�תint 
		int n=k;	 
		res+=" ";
		if(nums[number][3]==1)
			for(int j=0;j<k;j++) res+="-";//ÿһ�ʻ�Ҫ�ظ�k��
		else
			for(int j=0;j<k;j++) res+=" ";//ÿһ�ʻ�Ҫ�ظ�k��	
		res+=" ";
	}
	cout<<res<<endl;
	//�����н���
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";
		int number = s[i]-'0';
		if(nums[number][4]==1)
			res+="|";
		else
			res+=" ";
		for(int j=0;j<k;j++) res+=" ";
		if(nums[number][5]==1)
			res+="|";
		else
			res+=" ";
	}
	for(int i=0;i<k;i++){	//�ڶ���Ҫ�ظ����k�� 
		cout<<res<<endl;
	}//�����н���
	res = "";
	for(int i=0;i<size;i++){
		if(i!=0) res+=" ";//���˵�һ������,�����Ķ�Ҫ��ӿո�
		int number = s[i]-'0';	//�ַ�תint 
		int n=k;	 
		res+=" ";
		if(nums[number][6]==1)
			for(int j=0;j<k;j++) res+="-";//ÿһ�ʻ�Ҫ�ظ�k��
		else
			for(int j=0;j<k;j++) res+=" ";//ÿһ�ʻ�Ҫ�ظ�k��	
		res+=" ";
	}
	cout<<res<<endl;
	//�����н��� 
	return 0;
}
