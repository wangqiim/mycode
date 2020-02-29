#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,no;	//noÐòºÅ 
	string s,maxs;
	int len=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int size=s.size();
		if(size>len||(size==len&&s>maxs)){
			no = i+1;
			maxs = s;
			len = size;
		}
	}
	cout<<no<<endl<<maxs;
	return 0;
} 
