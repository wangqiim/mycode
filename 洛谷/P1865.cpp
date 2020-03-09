#include<cstdio>

const int maxm = 1000006;
bool nums[maxm];	//��������Ϊfalses
int prime[maxm];	//��i������ 
int cnt_pri = 0;
int acc[maxm]={0,0};//acc[i]:1-i����������
int cnt_acc = 2;
//ŷ��ɸ�� 
void find_prime(int n){
	for(int i=2;i<=n;i++){
		if(nums[i]==false){	//������ 
			prime[cnt_pri++] = i;
			acc[cnt_acc] = acc[cnt_acc-1]+1;
		}else
			acc[cnt_acc] = acc[cnt_acc-1];
		cnt_acc++;
		for(int j=0;j<cnt_pri&&i*prime[j]<=n;j++){
			nums[i*prime[j]] = true;
			if(i%prime[j]==0) break;
		}
	}
	return;
}


int main(){
	int n,m;	//ѯ�ʴ���n,��Χ1-m
	scanf("%d %d",&n,&m);
	find_prime(m);	//ŷ��ɸ 
	int l,r;
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		if(l<1||r>m) printf("Crossing the line\n");
		else printf("%d\n",acc[r]-acc[l-1]);
	}
	return 0;
}
