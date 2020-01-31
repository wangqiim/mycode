#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<set>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int n;

string to_f(string s,int &e){	//e��ָ��������β�� 
	while(s[0]=='0'&&s.size()>0){	//ɾ����ǰ����0�� 
		s.erase(s.begin());
	}
	if(s[0]=='.'){	//0.abc��ʽ 
		s.erase(s.begin());	//ɾ��С����
		while(s[0]=='0'&&s.size()>0){	//ɾ��ǰ��0 ��0.00abc 
			s.erase(s.begin());
			e--;
		}
	}else{	//ab.cd��ʽ 
		while(e<s.size()){
			if(s[e]!='.')
				e++;
			else{
				s.erase(s.begin()+e);	//ɾ��С���� 
				break;
			}
		}
	}
	if(s==""){
		e = 0;
	}
	if(s.size()>n)
		s = s.substr(0,n);
	while(s.size()<n){
		s+="0";
	}
	return s;	
}

int main(){
	string a,b;
	cin>>n>>a>>b;
	int e1=0,e2=0;
	a = to_f(a,e1);
	b = to_f(b,e2);
	if(a==b&&e1==e2)
		cout<<"YES 0."<<a<<"*10^"<<e1<<endl;
	else
		cout<<"NO 0."<<a<<"*10^"<<e1<<" 0."<<b<<"*10^"<<e2<<endl;
	return 0;
}
