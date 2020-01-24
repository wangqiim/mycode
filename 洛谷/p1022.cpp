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
	s+="+";	//再遍历s结束时，再处理一次 
	double a=0,b=0;		//转成形式ax=b
	int i;
	string tmp="";	//存需要处理的数,读完一个数处理一次
	int flag = 0;	//0表示+号,1表示减号 
	for(i=0;;i++){	//处理等号左边 
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
	for(i++;i<s.size();i++){	//处理等号右边 
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
	if(b==0){	// 防止出现 0/-1 = -0的情况。坑！！！！！ 
		printf("%c=%.3f",c,b);
	}else
		printf("%c=%.3f",c,(b/a));
	return 0;
}
