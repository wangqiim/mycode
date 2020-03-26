#include<cstdio>
const int maxn = 100005;	//0<=k<=n
bool boy[maxn];	//false该男孩没被选

int main(){
	int t,n,k;
	int choose;
	int add_x,add_y;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);	//n个女儿 
		for(int i=0;i<=n;i++)
			boy[i] = false;
		int optimal = true;
		int no_daught = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			int flag = 0;	//该女儿找不到对象 
			for(int j=0; j<k; j++){
				scanf("%d",&choose);
				if(flag==0&&boy[choose]==false){
					flag = 1;
					boy[choose] = true;
				}
			}
			if(flag==0){
				optimal = false;
				no_daught = (no_daught==0?i+1:no_daught);
			}
		}
		if(optimal){
			printf("OPTIMAL\n");
		}else{
			printf("IMPROVE\n");
			for(int index=1;index<=n;index++){
				if(boy[index]==false){	
					printf("%d %d\n",no_daught,index);
					break;
				}
			}
		}
	}
	return 0;
}
