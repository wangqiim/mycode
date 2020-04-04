#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t,n,x,a;
	int maxa;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		maxa = 0;
		bool flag = false;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(a == x)
				flag = true;
			maxa = max(maxa,a);
		}
		int res;
		if(flag)	//直接一步能跳到 
			res = 1;
		else if(maxa>x){
			res = 2;
		}else{
			if(x%maxa == 0)
				res = x/maxa;
			else
				res = x/maxa + 1;
		}
		printf("%d\n",res);
	}
	return 0;
}
