#include<cstdio>

const int maxn = 101;
int nums[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int flag = 1;	//1表示是输出的第一项(不能用"+"开头)
	for(int i=0;i<=n;i++)
		scanf("%d",&nums[i]);
		
	for(int i=0;i<=n;i++){
		if(flag==1&&i==n)	//只有一位时,是0也要输出 
			printf("%d",nums[i]);
		if(nums[i]!=0){	//非0才输出 
			if(flag){	//开头 
				flag = 0;
				if(i==n-1){	//x系数为1 
					if(nums[i]==1) printf("x");
					else if(nums[i]==-1) printf("-x");
					else printf("%dx",nums[i]);
				}
				else if(i==n) printf("%d",nums[i]);	//x系数为0 
				else{	//x系数>1 
					if(nums[i]==1) printf("x^%d",n-i);
					else if(nums[i]==-1) printf("-x^%d",n-i);
					else printf("%dx^%d",nums[i],n-i);
				}
			}else{
				if(nums[i]>0){	//正数
					if(i==n-1){	//系数为1 
						if(nums[i]==1) printf("+x");
						else printf("+%dx",nums[i]);
					}else if(i==n) printf("+%d",nums[i]);	//系数为0
					else{	//系数>1
						if(nums[i]==1) printf("+x^%d",n-i);
						else printf("+%dx^%d",nums[i],n-i);
					} 
				}
				else{	//负数 
					if(i==n-1){	//系数为1 
						if(nums[i]==-1) printf("-x");
						else printf("%dx",nums[i]);
					}else if(i==n) printf("%d",nums[i]);	//系数为0
					else{	//系数>1 
						if(nums[i]==-1) printf("-x^%d",n-i);
						else printf("%dx^%d",nums[i],n-i);
					}
				}
			}
		}
	}
	return 0;
} 
