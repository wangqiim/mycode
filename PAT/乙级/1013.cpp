#include<cstdio>
using namespace std;

const int maxn = 1000001;
bool p[maxn]={false};
int prime[maxn];
int pnum = 0;

void find_prime(int n){
	for(int i = 2;pnum < n;i++){
		if(p[i]==false){	//ÊÇËØÊý
			prime[pnum++]=i;
			for(int j = i+i;j<maxn;j=j+i){
				p[j]=true;
			} 
		}
	}
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	find_prime(n);
	for(int i=m;i<=n;i++){
		printf("%d",prime[i-1]);
		if((i-m+1)%10!=0&&i<n)
			printf(" ");
        else printf("\n");
	}
	return 0; 
}
