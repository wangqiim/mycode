#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
	int t,n;
	long long a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long sum = 0;
		long long maxnum;
		int flag = 0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a);
			if(i==0){
				maxnum = a;
				if(a>0)
					flag = 1;
				else
					flag = -1;
				continue;
			}
			if(a>0){
				if(flag==1){	//��һ��Ҳ���� 
					maxnum = max(maxnum,a);
				}else{
					sum += maxnum;
					maxnum = a;
					flag = 1;
				}
			}else{	//����Ϊ���� 
				if(flag==1){	//��һ������ 
					sum += maxnum;
					maxnum = a;
					flag = -1;
				}else{ 
					maxnum = max(maxnum,a);
				}
			}
		}
		sum += maxnum;
		printf("%lld\n",sum);
	}
	return 0;
} 
