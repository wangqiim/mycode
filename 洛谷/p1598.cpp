#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string row1,row2,row3,row4;
	int maxn=0;
	int a[26];	//���26����ĸ���ֵĴ��� 
	getline(cin,row1);
	getline(cin,row2);
	getline(cin,row3);
	getline(cin,row4);
	for(int i=0;i<26;i++){
		a[i] = 0;
	}
	for(int i=0;i<row1.size();i++){
		a[row1[i]-'A']++;
	}
	for(int i=0;i<row2.size();i++){
		a[row2[i]-'A']++;
	}
	for(int i=0;i<row3.size();i++){
		a[row3[i]-'A']++;
	}
	for(int i=0;i<row4.size();i++){
		a[row4[i]-'A']++;
	}
	for(int i=0;i<26;i++){
		maxn = max(maxn,a[i]);
	}
	for(int i=maxn;i>=1;i--){	//�������ִ�����ʼ���±��� 
		for(int j=0;j<26;j++){	//����ÿһ����ĸ�Ĵ��� 
			if(a[j]>=i){
				cout<<"*";
			}else{
				cout<<" ";
			}
			if(j!=25)	//����ĩβ 
				cout<<" ";
			else 	//ĩβ��Ҫ���� 
				cout<<endl;
		}
	}
	
	for(int i=0;i<26;i++){
		cout<<char('A'+i);
		if(i!=25)
			cout<<" "; 
	}
	return 0;
} 
