#include<cstdio>
#include<cmath>

bool a[14]={false},b[27]={false},c[27]={false};//���ϣ�����б��������Ԫ����
int loc[14];
int n,res;

void eight_queens(int now){	//������Ҫ�������
	if(now>n){	//��� 
		if(res<3)
			for(int i=1;i<=n;i++){
				if(i!=n) printf("%d ",loc[i]);
				else printf("%d\n",loc[i]);
			}
		res++;
	}
	else
		for(int i=1;i<=n;i++){	//���γ��ԷŸ���λ��
			if(!a[i]&&!b[now+i]&&!c[now-i+n]){
				a[i] = true;
				b[now+i] = true;
				c[now-i+n] = true;
				loc[now] = i;
				eight_queens(now+1);				
				a[i] = false;
				b[now+i] = false;
				c[now-i+n] = false;
			}
		}
	return;
}

int main(){
	scanf("%d",&n);
	res = 0;
	eight_queens(1);
	printf("%d",res);
	return 0;
}


/* �����ݹ�+��֦���һ�����������ᳬʱ 
#include<cstdio>
#include<cmath>

const int maxn = 14;
int n;
int res;
int loc[maxn];	//loc[1]��ʾ��һ�лʺ�ŵ�λ�� 

void eight_queens(int now){	//������Ҫ�������
	if(now>n){	//��� 
		if(res<3)
			for(int i=1;i<=n;i++){
				if(i!=n) printf("%d ",loc[i]);
				else printf("%d\n",loc[i]);
			}
		res++;
	}
	else
		for(int i=1;i<=n;i++){	//���γ��ԷŸ���λ��
			bool flag = true;
			for(int j=1;j<now;j++)	//�жϺ�֮ǰ�Ļʺ���û�г�ͻ
				if(loc[j]==i||abs(now-j)==abs(i-loc[j])){//��б
					flag = false;
					break;
				}
			if(flag){
			loc[now] = i;
				eight_queens(now+1);
			}	
		}
	return;
}

int main(){
	scanf("%d",&n);
	res = 0;
	eight_queens(1);
	printf("%d",res);
	return 0;
}*/
