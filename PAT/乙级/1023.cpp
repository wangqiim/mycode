#include<cstdio>


int main(){
	int nums[10];
	for(int i = 0;i<10;i++){
		scanf("%d",&nums[i]);
	}
	for(int i = 1 ;i<10;i++){
		if(nums[i]>0){
			printf("%d",i);
			nums[i]--;
			break;
		}	
	}
	for(int i = 0;i<10;i++){
		while(nums[i]>0){
			printf("%d",i);
			nums[i]--;
		}
	}
	return 0;
}
