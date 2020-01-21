#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int res1=1,res2=1;
	for(int i=0;i<s1.size();i++){
		res1 =res1 * (s1[i]-'A'+1)%47;
	}
	for(int i=0;i<s2.size();i++){
		res2 =res2 * (s2[i]-'A'+1)%47;
	}
	if(res1 == res2)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
	
}
