#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 1001;

queue<int> q;
bool ismem[maxn] = {false}; //�ڴ������޸����� 
int len = 0;	//��ʼ�ڴ��������� 

int main(){
	int m,n;	//m�ڴ�����,n���³���
	int res=0;	//���ֵ�Ĵ��� 
	scanf("%d %d",&m,&n);
	int num; 
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(!ismem[num]){//�ڴ���û�и�����
			res++;
			if(len<m){
				len++;
				q.push(num);
				ismem[num] = true;
			}else{	//�ڴ�����������Ҫ�滻 
				ismem[q.front()] = false;
				q.pop();
				q.push(num);
				ismem[num]=true;
			}
		}
	}
	printf("%d",res);
	return 0;
}
