#include<cstdio>

const int maxn = 101;
int nums[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int flag = 1;	//1��ʾ������ĵ�һ��(������"+"��ͷ)
	for(int i=0;i<=n;i++)
		scanf("%d",&nums[i]);
		
	for(int i=0;i<=n;i++){
		if(flag==1&&i==n)	//ֻ��һλʱ,��0ҲҪ��� 
			printf("%d",nums[i]);
		if(nums[i]!=0){	//��0����� 
			if(flag){	//��ͷ 
				flag = 0;
				if(i==n-1){	//xϵ��Ϊ1 
					if(nums[i]==1) printf("x");
					else if(nums[i]==-1) printf("-x");
					else printf("%dx",nums[i]);
				}
				else if(i==n) printf("%d",nums[i]);	//xϵ��Ϊ0 
				else{	//xϵ��>1 
					if(nums[i]==1) printf("x^%d",n-i);
					else if(nums[i]==-1) printf("-x^%d",n-i);
					else printf("%dx^%d",nums[i],n-i);
				}
			}else{
				if(nums[i]>0){	//����
					if(i==n-1){	//ϵ��Ϊ1 
						if(nums[i]==1) printf("+x");
						else printf("+%dx",nums[i]);
					}else if(i==n) printf("+%d",nums[i]);	//ϵ��Ϊ0
					else{	//ϵ��>1
						if(nums[i]==1) printf("+x^%d",n-i);
						else printf("+%dx^%d",nums[i],n-i);
					} 
				}
				else{	//���� 
					if(i==n-1){	//ϵ��Ϊ1 
						if(nums[i]==-1) printf("-x");
						else printf("%dx",nums[i]);
					}else if(i==n) printf("%d",nums[i]);	//ϵ��Ϊ0
					else{	//ϵ��>1 
						if(nums[i]==-1) printf("-x^%d",n-i);
						else printf("%dx^%d",nums[i],n-i);
					}
				}
			}
		}
	}
	return 0;
} 
