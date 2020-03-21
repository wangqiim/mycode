#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 2e5+1;
char nums[maxn];

int main(){
	int t;	//t×éÑùÀı
	int res,flag;
	int len;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%s",&nums);
		len = strlen(nums);
		flag = 0;
		res = 0;
		for(int j=0;j<len;j++){
			if(nums[j]=='L'){
				flag++;
				res = max(res,flag);
			}else
				flag=0;
		}
		printf("%d\n",res+1);
	}
	return 0;
}
