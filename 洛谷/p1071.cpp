#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int hashmap[26];	//���Ķ�ԭ�� 
int hashmap2[26];	//ԭ�Ķ����� 

int main(){
	string s1,s2,s3;//s1������Ϣ,s2ԭ��,s3��Ҫ����ļ�����Ϣ
	string res = "";
	cin>>s1>>s2>>s3;
	for(int i=0;i<26;i++){
		hashmap[i] = -1;
		hashmap2[i] = -1;
	}
	int n1,n2,n3;
	n1 = s1.size();n2 = s2.size();
	n3 = s3.size();
	int n = 0;	//�Ѿ����ڵ�ӳ�� 
	for(int i=0;i<n1;i++){
		if(hashmap[s1[i]-'A']==-1&&hashmap2[s2[i]-'A']==-1){	//��δӳ�� 
			hashmap[s1[i]-'A'] = s2[i]-'A';
			hashmap2[s2[i]-'A'] = s1[i]-'A';
			n++;
		}
		else
			if(hashmap[s1[i]-'A']!=s2[i]-'A'||hashmap2[s2[i]-'A']!=s1[i]-'A'){
				cout<<"Failed";	//һ�Զ�,3�ʹ��� 
				return 0;
			}
	}
	if(n!=26){
		cout<<"Failed";	//�м�������ӳ��,���� 
		return 0;	
	}
	for(int i=0;i<n3;i++)
		res.push_back((char)(hashmap[s3[i]-'A']+'A'));
	cout<<res;
	return 0;
}
