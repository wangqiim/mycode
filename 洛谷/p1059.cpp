#include<cstdio>

const int maxn = 1001;
bool nums[maxn]={false};

int main(){	//Õ∞≈≈–Ú 
	int n,res=0;
	scanf("%d",&n);
	int num;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(!nums[num]){
			nums[num] = true;
			res++;
		}
	}
	printf("%d\n",res);
	for(int i=1;i<maxn;i++){
		if(nums[i])
			printf("%d ",i);
	}
	return 0;
} 
