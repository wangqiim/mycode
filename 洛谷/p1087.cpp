#include<iostream>
#include<string>
using namespace std;

int n;//长度为2^N的01串	
string s,res;

char  merge(int left,int right){	//返回当前串是什么串 
	if(left==right){
		if(s[left]=='0'){
			res.push_back('B');
			return 'B';
		}
		else{
			res.push_back('I');
			return 'I';
		}
	}
	int mid = (left+right)/2;
	char l_son=merge(left,mid);
	char r_son=merge(mid+1,right);
	if(l_son=='B'&&r_son=='B'){
		res.push_back('B');
		return 'B';
	}
	else if(l_son=='I'&&r_son=='I'){
		res.push_back('I');
		return 'I';
	}
	else{
		res.push_back('F');
		return 'F';
	}
}

int main(){	
	cin>>n>>s;
	merge(0,s.size()-1);
	cout<<res;
	return 0;
} 
