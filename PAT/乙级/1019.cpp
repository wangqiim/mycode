#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

void nums_to_array(int nums,int array[]){
	for(int i = 0 ;i<4;i++){
		array[i]= nums%10;
		nums /= 10;
	}
}

int array_to_nums(int array[]){
	int sum = 0; 
	for(int i = 0 ;i<4;i++){
		sum = sum*10 + array[i];
	}
	return sum;
}

int main(){
	int n,max,min;
	int nums[4];
	scanf("%d",&n);
	while(1){
		nums_to_array(n,nums);
		sort(nums,nums+4,cmp);
		max = array_to_nums(nums);
		sort(nums,nums+4);
		min = array_to_nums(nums);
		n = max-min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n==0||n==6174)   //结果是0或6174则退出循环
			break;
	}
	return 0;
}
