#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	char str[256];
	scanf("%s",str);
	int l_cnt=0;//�����ŵ�����
	bool res = true;
	for(int i=0;str[i]!='@';i++){
		if(str[i]=='('){
			l_cnt++;	
		}
		else if(str[i]==')'){
			if(--l_cnt<0){
				res = false;
				break;
			}
		}
	} 
	if(l_cnt!=0||res==false)
		printf("NO");
	else	//���������겢����;û�г�ͻ 
		printf("YES");
	return 0;	
}
