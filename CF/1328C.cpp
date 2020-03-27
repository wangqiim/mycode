#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 50004;
char nums[maxn];
char a[maxn];
char b[maxn];

int main(){
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",nums);
		int flag = 1;	//目前a,b前缀相等 
		for(int i=0;i<n;i++){	//定义a>=b
			if(i==0){
				if(nums[i]=='0'){
					a[i] = '2';
					b[i] = '1';
					flag = 0;
				}else if(nums[i]=='1'){
					a[i] = '2';
					b[i] = '2';
				}else{
					a[i] = '1';
					b[i] = '1';				
				}
			}
			else{
				if(flag){	//a==b
					if(nums[i]=='0'){
						a[i] = '0';
						b[i] = '0';
					}else if(nums[i]=='1'){
						a[i] = '1';
						b[i] = '0';
						flag = 0;
					}else{
						a[i] = '1';
						b[i] = '1';
					}
				}else{	//a>b
					if(nums[i]=='0'){
						a[i] = '0';
						b[i] = '0';
					}else if(nums[i]=='1'){
						a[i] = '0';
						b[i] = '1';
					}else{
						a[i] = '0';
						b[i] = '2';
					}
				}
			}
		}
		a[n] = 0;
		b[n] = 0;
		printf("%s\n%s\n",a,b);
	}
	return 0;
}
