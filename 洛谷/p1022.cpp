#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int str_2_int(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		res = res*10+(s[i]-'0');
	}
	return res;
}

int main(){
	string s;
	char c;
	cin>>s;
	s+="+";	//�ٱ���s����ʱ���ٴ���һ�� 
	double a=0,b=0;		//ת����ʽax=b
	int i;
	string tmp="";	//����Ҫ�������,����һ��������һ��
	int flag = 0;	//0��ʾ+��,1��ʾ���� 
	for(i=0;;i++){	//����Ⱥ���� 
		if(s[i]>='0'&&s[i]<='9'){
			tmp+=s[i];
		}else if(s[i]>='a'&&s[i]<='z'){
			c = s[i];
			if(tmp==""){
				if(flag==0)
					a += 1;
				else
					a -= 1;
			}
			else{
				if(flag==0)
					a += str_2_int(tmp);
				else
					a -= str_2_int(tmp);
			}
			tmp = "";
			flag = 0;
		}else{
			if(flag==0)
				b -= str_2_int(tmp);
			else
				b += str_2_int(tmp);
			tmp = "";
			if(s[i]=='+')
				flag=0;
			else if(s[i]=='-')
				flag=1;
			else
				break;
		}
	}
	flag = 0;
	for(i++;i<s.size();i++){	//����Ⱥ��ұ� 
		if(s[i]>='0'&&s[i]<='9'){
			tmp+=s[i];
		}else if(s[i]>='a'&&s[i]<='z'){
			c = s[i];
			if(tmp==""){
				if(flag==0)
					a -= 1;
				else
					a += 1;
			}
			else{
				if(flag==0)
					a -= str_2_int(tmp);
				else
					a += str_2_int(tmp);
			}
			tmp = "";
			flag = 0;
		}else{
			if(flag==0)
				b += str_2_int(tmp);
			else
				b -= str_2_int(tmp);
			tmp = "";
			if(s[i]=='+')
				flag=0;
			else if(s[i]=='-')
				flag=1;
			else
				break;
		}
	}
	if(b==0){	// ��ֹ���� 0/-1 = -0��������ӣ��������� 
		printf("%c=%.3f",c,b);
	}else
		printf("%c=%.3f",c,(b/a));
	return 0;
}
