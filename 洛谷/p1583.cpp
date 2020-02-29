#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 20001;

int E[11];
struct people{
	int no;	//��ʼ��� 
	int w;	//��ʼȨֵ 
}W[maxn];

bool cmp(people a,people b){
	if(a.w!=b.w)
		return a.w>b.w;
	else	//���Ȩֵ��ͬ�����С������ 
		return a.no<b.no;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=10;i++)
		scanf("%d",&E[i]);
	for(int i=1;i<=n;i++){
		W[i].no = i;
		scanf("%d",&W[i].w);
	}
	sort(W+1,W+1+n,cmp); //�Ȱ�����Ȩֵ����,�±�ΪD[i]
	for(int i=1;i<=n;i++){	//��Ȩֵ����Ϊ����E[i] 
		W[i].w += E[(i-1)%10+1]; 
	}
	sort(W+1,W+1+n,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",W[i].no);
	return 0;
}
