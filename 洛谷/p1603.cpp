#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> hashmap;
int nums[6];

int main(){	//这题目的描述真的诡异 
	hashmap["one"]=1;hashmap["two"]=2;hashmap["three"]=3;hashmap["four"]=4;hashmap["five"]=5;
	hashmap["six"]=6;hashmap["seven"]=7;hashmap["eight"]=8;hashmap["nine"]=9;hashmap["ten"]=10;
    hashmap["eleven"]=11;hashmap["twelve"]=12;hashmap["thirteen"]=13;hashmap["fourteen"]=14;
	hashmap["fifteen"]=15;hashmap["sixteen"]=16;hashmap["seventeen"]=17;hashmap["eighteen"]=18;
	hashmap["nineteen"]=19;hashmap["twenty"]=20;
	hashmap["a"]=1;hashmap["both"]=2;hashmap["another"]=1;
	hashmap["first"]=1;hashmap["second"]=2;hashmap["third"]=3;
	string s;
	int m=0;
	for(int i=0;i<6;i++){
		cin>>s;
		if(s.size()>0&&(s[0]<'a'||s[0]>'z'))
			s[0] = s[0] - 'A' + 'a';
		if(hashmap.count(s)>0){
			nums[m++] = hashmap[s]*hashmap[s]%100;
		}
	}
	sort(nums,nums+m);
	if(m==0){
		cout<<0;
		return 0;
	}
	cout<<nums[0];
	for(int i = 1;i<m;i++){
		if(nums[i]<10){
			cout<<"0"<<nums[i];
		}
		else cout<<nums[i];
	}
	return 0;
}
