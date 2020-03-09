#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 1e8+1;
const int maxq = 1e6+1;
bool nums[maxn];	//false ��ʾ������ 
int prime[maxn];
int cnt=0;
	//ʹ��ŷ��ɸ������֤ÿ����n��ֻ������С��������a*(n/a)ɸȥһ��! 
void find_prime(int n){	//��ʼ��nums[3-n]
	for(int i=2;i<n;i++){
		if(nums[i]==false)
			prime[++cnt] = i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){	//����֮ǰ������ 
			nums[prime[j]*i] = true;
			if(i%prime[j] == 0)	break;
			//������ԭ����,i���Ѿ���a(prime[j])�����������b(prime[j+1)
			//j������ѭ��ֻ������һ�����ȱ�aɸȥһ��,�ֱ� bɸȥһ�� 
		} 
	}
	return;
}

int main(){
	int n,q,k;	//��Χ�Ͳ�ѯ���� 
	scanf("%d %d",&n,&q);
	find_prime(n);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		printf("%d\n",prime[k]);
	}
	return 0;
}

/*	//����ɸ����ʱGG 
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 1e8+1;
const int maxq = 1e6+1;
bool nums[maxn];	//false ��ʾ������ 
int prime[maxn];
int res[maxq];

void find_prime(int n){	//��ʼ��nums[3-n]
	int cnt=1;
	for(int i=2;i<n;i++){
		if(nums[i]) continue;
		prime[cnt++] = i;
		for(int j=i+i;j<=n;j+=i){
			nums[j] = true;
		} 
	}
	return;
}

int main(){
	int n,q,k;	//��Χ�Ͳ�ѯ���� 
	scanf("%d %d",&n,&q);
	find_prime(n);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		res[i]=prime[k];
	}
	for(int i=0;i<q;i++)
		printf("%d\n",res[i]);
	return 0;
}*/
