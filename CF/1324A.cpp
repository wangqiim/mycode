#include<cstdio>

int main(){
	int t,n;	//t组样例
	int pre,a;	//高度
	bool flag;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		flag = true;
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			if(j==0){
				pre = a;
				continue;
			} 
			if((a-pre)%2!=0)
				flag = false;
			pre = a;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
