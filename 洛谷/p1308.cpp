#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
	string sub,str;
	int size1,size2;
	int i,j,num=0,begin=-1;
	getline(cin,sub);
	getline(cin,str);
	size1 = sub.size();
	size2 = str.size();
	str += ' ';	//�ھ���ĩβ��һ���ո񷽱㶨λ���ʵĽ����� 
	for(i=0;i<size1;i++){
    	sub[i]=tolower(sub[i]);
    }
    for(i=0;i<size2;i++){
		str[i]=tolower(str[i]);
    }
	for(i=0;i<=size2-size1;i++){
		if(i>0&&str[i-1]!=' ')	//iû�ƶ������ʿ�ͷ��λ�� 
			continue;
		for(j=0;j<size1;j++){
			if(sub[j]!=str[i+j])	//����ƥ��
				break;
		}
		if(j==size1&&str[i+j]==' '){	//��������ѭ��ʱ,���ߵĵ�������ƥ��ɹ��� 
			num++;
			if(begin == -1)
				begin = i;
		}
	}
	if(begin == -1)
		cout<<-1;
	else
		cout<<num<<" "<<begin;
	return 0;
}
