#include<cstdio>
#include<cstring>

const int MAXN = 100005;
const int MOD = 1000000007;

char input_str[MAXN]; //�����ַ���
int left_P_num[MAXN]={0};	//��λ�����p�ĸ���

int main(){
	int res=0;
	scanf("%s",input_str);
	int size = strlen(input_str);
	for(int i=1;i<size;i++){	//�����Ҽ����left_P_num���� 
		if(input_str[i-1]=='P'){
			left_P_num[i] = left_P_num[i-1]+1;
		}
		else{
			left_P_num[i] = left_P_num[i-1];
		}
	}
	int num=0;	//��¼�����������ʱ��ǰT�ĸ��� 
	for(int i=size-1;i>0;i--){
		if(input_str[i]=='T'){
			num++;
		}else if(input_str[i]=='A'){
			res = (res + num*left_P_num[i])%MOD;
		}
	}
	printf("%d\n",res);
	return 0;
}
